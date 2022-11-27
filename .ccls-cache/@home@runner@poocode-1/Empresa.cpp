#include "Empresa.hpp"

#include <iostream>
#include <list>
#include <string>

// Métodos privados
Empresa::Empresa(){};

Empresa* Empresa::_instance = nullptr;

Empresa* Empresa::getInstance(){
    if(_instance == nullptr)
    {
        _instance = new Empresa();
    }
    return _instance;
}

std::list<Funcionario>* Empresa::getFuncionarios(){return &_funcionarios;}

std::list<Cargo>* Empresa::getCargos(){return &_cargos;}

std::list<Departamento>* Empresa::getDepartamentos(){return &_departamentos;}

std::list<Produto>* Empresa::getProdutos(){return &_produtos;}

std::list<Cliente>* Empresa::getClientes(){return &_clientes;}

std::list<Lote>* Empresa::getLotes(){return &_lotes;}

std::list<Venda>* Empresa::getVendas(){return &_vendas;}

std::list<Grupos>* Empresa::getGrupos(){return &_grupos_de_permissoes;}

std::list<MateriaPrima>* Empresa::getMP(){return &materiaprima_;}

std::list<Fornecedor>* Empresa::getFornecedores(){return &_fornecedores;}

//std::pair<float,float> Empresa::getCoordenadas(){return coordenadas_;}

Endereco Empresa::getEndereco(){return _endereco;}

void Empresa::addCargo(std::string nome){
if(!Usuario::getInstance().checkPermissao("Cadastrar-cargo"))
  {
    ExcecaoAcessoNegado E ("addCargo");
    E.criaLogExcecaoAcessoNegado(Data::dateNow(), "Cargo", Usuario::getInstance().getCadastro());
    throw  E;
  }
  
  Cargo novo(nome);
  _cargos.push_back(novo);
  
  LogEscrita *a  = new LogEscrita(Data::dateNow(), "Empresa", Usuario::getInstance().getCadastro(), "_cargos: +", novo.getNomeCargo());
  Log_List::addLog(a);
}

void Empresa::addOrdemProducao(OrdemProducao ordem)
{
  _Ordens_de_producao_em_aberto.push_back(ordem);
  std::cout << "Ordem para produção de " << ordem.getQtd() << "X " << ordem.getProduto()->getNome() << " gerada" << std::endl;
}

void Empresa::validaOrdemProducao(std::string nome_do_produto)
{
  for (auto it = _Ordens_de_producao_em_aberto.begin(); it != _Ordens_de_producao_em_aberto.end(); ++it)
  {
    if((*it).getProduto()->getNome().compare(nome_do_produto) != 0) continue;
    else
    {
      (*it).getProduto()->subtrairMateriaPrima((*it).getQtd());
      Lote l(Data::dateNow(), (*it).getProduto()->getCodigo(),(*it).getQtd());
      _lotes.push_back(l);
      (*it).getProduto()->addLote(l.getCodigo(), (*it).getQtd());
      _Ordens_de_producao_validadas.push_back((*it));
      _Ordens_de_producao_em_aberto.erase(it);
    }
  }
  throw ExcecaoPadrao("O produto em específico não possui ordem de produção em aberto");
}

Cargo* Empresa::getCargo(std::string nome){
  for (std::list<Cargo>::iterator it = _cargos.begin(); it != _cargos.end(); ++it)
  {
    if((*it).getNomeCargo().compare(nome) != 0) continue;
    else return &(*it);
  }
  return nullptr;
}

void Empresa::addDepartamento(std::string nome){
  if(!Usuario::getInstance().checkPermissao("Cadastrar-departamento"))
  {
    ExcecaoAcessoNegado E ("addDepartamento");
    E.criaLogExcecaoAcessoNegado(Data::dateNow(), "Departamento", Usuario::getInstance().getCadastro());
    throw  E;
  }
  
  Departamento novo(nome);
  _departamentos.push_back(novo);
  
  LogEscrita *a = new LogEscrita(Data::dateNow(), "Empresa", Usuario::getInstance().getCadastro(), "_departamentos: +", novo.getNomeDepartamento());
  Log_List::addLog(a);
}

Departamento* Empresa::getDepartamento(std::string nome){
  for (std::list<Departamento>::iterator it = _departamentos.begin(); it != _departamentos.end(); ++it)
  {
    if((*it).getNomeDepartamento().compare(nome) != 0) continue;
    else return &(*it);
  }
  return nullptr;
}

bool Empresa::checkCargo(std::string cargo){
  for(auto it = getCargos()->begin(); it != getCargos()->end(); it++){
    if(cargo == it->getNomeCargo()) return true;
  }
  return false;
}

void Empresa::admitirFuncionario(Funcionario a, const double& salario, std::string cargo, std::string departamento){
  if(!Usuario::getInstance().checkPermissao("Cadastrar-funcionário"))
  {
    ExcecaoAcessoNegado E ("admitirFuncionario");
    E.criaLogExcecaoAcessoNegado(Data::dateNow(), "Funcionario", Usuario::getInstance().getCadastro());
    throw  E;
  }
  
  for (std::list<Funcionario>::iterator it = _funcionarios.begin(); it != _funcionarios.end(); ++it)
  {
    if((*it).getMatricula() != a.getMatricula()) continue;
    else
    {
      (*it).Admitir(salario, *getCargo(cargo), *getDepartamento(departamento));
      return;
    }
  }
  _funcionarios.push_back(a);
  LogEscrita *x = new LogEscrita(Data::dateNow(), "Funcionario", Usuario::getInstance().getCadastro(), "", a.getNome() + "|" + a.getEmail() + "|" + a.getCertificado() + "|" + a.getNascimento().getData() + "|" + std::to_string(a.getMatricula()));
  Log_List::addLog(x);
}

void Empresa::Demitir(Funcionario funcionario){
  if(!Usuario::getInstance().checkPermissao("Demitir-funcionário"))
  {
    ExcecaoAcessoNegado E ("Demitir funcionario");
    E.criaLogExcecaoAcessoNegado(Data::dateNow(), "Funcionario", Usuario::getInstance().getCadastro());
    throw  E;
  }

  funcionario.getVeiculo()->removeFuncionario(&funcionario);
  funcionario.getCargo()->removeFuncionario(funcionario.getMatricula());
  funcionario.getDepartamento()->demitirFuncionario(&funcionario);
  
  for (std::list<Funcionario>::iterator it = _funcionarios.begin(); it != _funcionarios.end(); ++it)
  {
    if((*it).getMatricula() == funcionario.getMatricula()) (*it).Demitir();
  }
}

void Empresa::addProduto(Produto produto){
  if(!Usuario::getInstance().checkPermissao("Cadastrar-produto"))
  {
    ExcecaoAcessoNegado E ("addProduto");
    E.criaLogExcecaoAcessoNegado(Data::dateNow(), "Produto", Usuario::getInstance().getCadastro());
    throw  E;
  }
  
  _produtos.push_back(produto);
  
  LogEscrita *a  = new LogEscrita(Data::dateNow(), "Empresa", Usuario::getInstance().getCadastro(), "_produtos: +", produto.getNome());
  Log_List::addLog(a);
  
}


void Empresa::produzirProduto(int codigo, int qtd){
  if(!Usuario::getInstance().checkPermissao("Produzir-produto"))
  {
    ExcecaoAcessoNegado E ("produzirProduto");
    E.criaLogExcecaoAcessoNegado(Data::dateNow(), "Produto", Usuario::getInstance().getCadastro());
    throw  E;
  }
  Produto* temp;
  for(auto it = getProdutos()->begin(); it != getProdutos()->end(); it++){
    if(it->getCodigo() == codigo){
      temp = &(*it);
      break;
    }
  }

  if(qtd < temp->getLoteMin()) qtd = temp->getLoteMin();
  temp->addLote(temp->getLote()+1,qtd);

  //getProduto
}

Produto* Empresa::getProduto(std::string nome){
  for (auto it = _produtos.begin(); it != _produtos.end(); ++it)
  {
    if(it->getNome().compare(nome) != 0) continue;
    else{
      LogLeitura* a = new LogLeitura(Data::dateNow(),"Produto",Usuario::getInstance().getCadastro(),it->getNome());
      Log_List::addLog(a);
      return &(*it);
    }
  }
  throw  ExcecaoPadrao ("Produto não encontrado");
}

Cliente* Empresa::getCliente(std::string nome){
  for (auto it = _clientes.begin(); it != _clientes.end(); ++it)
  {
    if((*it).getNome().compare(nome) != 0) continue;
    else {
      LogLeitura* a = new LogLeitura(Data::dateNow(),"Cliente",Usuario::getInstance().getCadastro(),it->getNome());
      Log_List::addLog(a);
      return &(*it);
    }
  }
  throw  ExcecaoPadrao ("Cliente não encontrado");
}

MateriaPrima* Empresa::getMateriaPrima(std::string nome){
  if(!Usuario::getInstance().checkPermissao("Ler-matéria-prima"))
  {
    ExcecaoAcessoNegado E ("getMateriaPrima");
    E.criaLogExcecaoAcessoNegado(Data::dateNow(), "MateriaPrima", Usuario::getInstance().getCadastro());
    throw  E;
  }
  
  for (auto it = materiaprima_.begin(); it != materiaprima_.end(); ++it)
  {
    if((*it).getNome().compare(nome) != 0) continue;
    else{
      LogLeitura* a = new LogLeitura(Data::dateNow(),"MateriaPrima",Usuario::getInstance().getCadastro(),it->getNome());
      Log_List::addLog(a);
      return &(*it);
      }
  }
  return nullptr;
}

Funcionario* Empresa::getFuncionario(std::string nome)
{
  for (auto it = _funcionarios.begin(); it != _funcionarios.end(); ++it)
  {
    if((*it).getNome().compare(nome) != 0) continue;
    else {
      LogLeitura* a = new LogLeitura(Data::dateNow(),"Funcionario",Usuario::getInstance().getCadastro(),it->getNome());
      Log_List::addLog(a);
      return &(*it);
      }
  }
  throw  ExcecaoPadrao ("Funcionario não encontrado");
}

void addOrdemProducao(OrdemProducao o)
{
  Empresa* empresa = Empresa::getInstance();
  empresa->addOrdemProducao(o);
}