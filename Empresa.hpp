#ifndef EMPRESA_H
#define EMPRESA_H

#include "Funcionario.hpp"
#include "Cargo.hpp"
#include "Produto.hpp"
#include "Cliente.hpp"
#include "Lote.hpp"
#include "Venda.hpp"
#include "Departamento.hpp"
#include "Grupos.hpp"
#include "MateriaPrima.hpp"
#include "Fornecedor.hpp"
#include "Cadastro.hpp"
#include "ExcecaoPadrao.hpp"

#include <iostream>
#include <list>
#include <string>

class Empresa {
private:

  static Empresa* _instance;

  std::list<Funcionario> _funcionarios;
  std::list<Cargo> _cargos;
  std::list<Departamento> _departamentos;
  std::list<Produto> _produtos;
  std::list<Cliente> _clientes;
  std::list<Lote> _lotes;
  std::list<Venda> _vendas;
  std::list<Grupos> _grupos_de_permissoes;
  std::list<MateriaPrima> materiaprima_;
  std::list<Fornecedor> _fornecedores;
  std::list<Cadastro> _cadastros;
  std::pair<float,float> coordenadas_;
 /**
   * @brief Construtor padrao que cria a empresa
   *
   * @param nome nome da empresa
   */
  Empresa(std::pair<float,float> coordenadas);
public:
 
  

  //void setFuncionarios(std::list<Funcionario> funcionarios);
  //void setCargos(std::list<Cargo> cargos);
  //void setDepartamentos(std::list<Departamento> departamentos);
  //void setProdutos(std::list<Produto> produtos);
  //void setClientes(std::list<Cliente> clientes);
  //void setLotes(std::list<Lote> lotes);
  //void setVendas(std::list<Venda> vendas);
  /**
   * @brief retorna ponteiro para a empresa
   */
  static Empresa* getInstance();

  std::list<Funcionario>* getFuncionarios();
  std::list<Cargo>* getCargos();
  std::list<Departamento>* getDepartamentos();
  std::list<Produto>* getProdutos();
  std::list<Cliente>* getClientes();
  std::list<Lote>* getLotes();
  std::list<Venda>* getVendas();
  std::list<Grupos>* getGrupos();
  std::list<MateriaPrima>* getMP();
  std::list<Fornecedor>* getFornecedores();
  /**
   * @brief Adiciona um funcionário pra lista de funcionarios
   *
   * @param funcionario Funcionário desejado
   */
  void addFuncionario(Funcionario funcionario);

  /**
   * @brief Remove um funcionário da lista de funcionarios, mas primeiro confere se o funcionário está na lista
   *
   * @param funcionario Funcionário desejado
   */
  void removeFuncionario(Funcionario funcionario);

  /**
   * @brief Ao se demitir um funcionário, se retira ele da lista
   *
   * @param funcionario Funcionário desejado
   */
  void Demitir(Funcionario funcionario);

  /**
   * @brief Remove um funcionário da lista de funcionarios do departamento, mas primeiro confere se o funcionário está na lista
   *
   * @param a ponteiro para o funcionário desejado
   */
  void admitirFuncionario(Funcionario* a, const double salario, Cargo &cargo);

  /**
   * @brief Cadastro de usuario.
   *
   * @param lista de grupos de permissão que o usuario possui acesso
   */void cadastrarUsuario(std::string ID, std::string senha, std::list<std::string> permissoes)
    {
      std::list<Grupos*> gp_permissoes;
      
      for (std::list<std::string>::iterator it = permissoes.begin(); it != permissoes.end(); ++it)
      {
        try
        {
          gp_permissoes.push_back(procurarGrupo(*it));  //procura o grupo cujo o nome pertence a permissoes
        }
        catch(const ExcecaoPadrao& E)  //caso o grupo não exista
        {
          std::cout << E.getMensagem() << std::endl;
          continue; //pula para a próxima iteração
        }
      }
      Cadastro temp(ID, senha, gp_permissoes);
      this->_cadastros.push_back(temp);
    }

  /**
   * @brief Função que procura um usuário na lista de cadastros.
   *
   * @param identificadação e senha.
   * @return o ponteiro para o cadastro do usuário.
   */Cadastro* loginUsuario(std::string ID, std::string senha)
    {
      for (std::list<Cadastro>::iterator it = _cadastros.begin(); it != _cadastros.end(); ++it)
      {
        if(it->getID() != ID) continue;  //pula para a proxima iteração sempre que o ID é diferente de .getID()
        if(it->getSenha() == senha){
          Cadastro* Login;
          Login = &(*it);
          return Login;
          }
          else throw ExcecaoPadrao("Senha incorreta","Empresa.loginUsuario");
      }
      throw ExcecaoPadrao("Usuario não encontrado","Empresa.loginUsuario");
    }

  /**
   * @brief Cadastro de grupos de permissão.
   *
   * @param lista de grupos de permissão que o usuario possui acesso
   */void cadastrarGrupo(std::string nome, std::list<std::string> permissoes)
    {
      this->_grupos_de_permissoes.push_back(Grupos(nome, permissoes));
    }

  /**
   * @brief Cadastro de grupos de permissão.
   *
   * @param lista de grupos de permissão que o usuario possui acesso
   */Grupos* procurarGrupo(std::string nome)
    {
      for (std::list<Grupos>::iterator it = _grupos_de_permissoes.begin(); it != _grupos_de_permissoes.end(); ++it)
      {
        if(it->getNomeGrupo() == nome){
          Grupos* Grupo;
          Grupo = &(*it);
          return Grupo;
          }
      }
      throw ExcecaoPadrao("Grupo não encontrado","Empresa.procurarGrupo");
    }
};

#endif