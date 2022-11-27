#include "Empresa.hpp"
#include "ExcecaoPadrao.hpp"
#include "OrcamentoVenda.hpp"
#include "Usuario.hpp"
#include "VendaOnline.hpp"
#include "Endereco.hpp"
#include <iostream>
#include "FormaDePagamento.hpp"
#include "LogList.hpp"

#define DisplayFuncionario(f)                                                  \
  std::cout << std::endl                                                       \
            << f.getNome() << std::endl                                        \
            << f.getEmail() << std::endl                                       \
            << f.getCertificado() << std::endl                                 \
            << f.getNascimento().getData() << std::endl                        \
            << f.getEndereco().print() << std::endl                            \
            << f.getMatricula() << std::endl                                   \
            << std::endl;

#define DisplayCliente(F)                                                      \
  std::cout << std::endl                                                       \
            << F.getNome() << std::endl                                        \
            << F.getEmail() << std::endl                                       \
            << F.getCertificado() << std::endl                                 \
            << F.getTelefone() << std::endl                                    \
            << F.getTipo() << std::endl                                        \
            << std::endl;

#define DisplayMateriaPrima(M)                                                 \
  std::cout << "Código- " << M.getCodigo() << "\n Quantidade- "                \
            << M.getQtd() << M.getUnidade() << "\n Estoque Mínimo- "           \
            << M.getEstoqueMin() << M.getUnidade() << "\n";

int main() {
  Log_List::getInstance();
  Venda_Online* venda = &Venda_Online::getInstance();
  Endereco::setAPI_key("AIzaSyBY57rOTWQJzN2SMy1F40sU6uWupKGrnNI");
  FormaDePagamento::addTipo("Dinheiro");

  //◦Instanciar um objeto da classe Empresa.
  Empresa *empresa = Empresa::getInstance();
  
  empresa->setEndereco(Endereco("Av. Antônio Abrahão Caram", 1001));
  
  std::cout << "criada Empresa nas coordenadas"<< empresa->getEndereco().print() << std::endl;

  // ◦Instanciar um objeto de um usuário logado que deverá ter
  // permissão de acesso à todas as funcionalidades, exceto ao
  // método que realiza a exclusão de um funcionário.
  std::list<std::string> permissoes;
  permissoes.push_back("Cadastrar-funcionário");
  permissoes.push_back("Cadastrar-fornecedor");
  permissoes.push_back("Cadastrar-produto");
  permissoes.push_back("Cadastrar-grupo");
  permissoes.push_back("Cadastrar-departamento");
  permissoes.push_back("Cadastrar-cargo");
  permissoes.push_back("Cadastrar-matéria-prima");
  permissoes.push_back("Cadastrar-produto");
  //- Criação de um grupo de permissão.
  //                       |nome|     |permissoes|
  try {
    empresa->cadastrarGrupo("Gerente", permissoes);
  } catch (ExcecaoAcessoNegado E) {
    std::cout << E.resumo() << std::endl;
  }

  permissoes.clear();
  permissoes.push_back("Gerar-orçamento");
  permissoes.push_back("Cadastrar-cliente");
  permissoes.push_back("Produzir-produto");
  permissoes.push_back("Vender");
  permissoes.push_back("Ler-matéria-prima");
  try {
    empresa->cadastrarGrupo("Vendedor", permissoes);
  } catch (ExcecaoAcessoNegado E) {
    std::cout << E.resumo() << std::endl;
  }

  //- Criação do cadastro de um usuário.
  std::string grupos[] = {"Gerente", "Vendedor"};
  //                          |ID|    |senha|    |grupos|
  empresa->cadastrarUsuario(
      "fulano", "12345",
      std::list<std::string>(std::begin(grupos), std::end(grupos)));

  //- Realizar o login do usuário.
  //
  try {
    Usuario::getInstance().Login(empresa->loginUsuario("fulano", "12345"));
  } catch (ExcecaoPadrao E) // Caso a senha ou o ID estejam errados
  {
    std::cout << E.getMensagem() << std::endl;
  }

  // ◦Comprovar o funcionamento do singleton do usuário
  // logado.//==================|
  try {
    Usuario::getInstance().Login(empresa->loginUsuario(
        "fulano",
        "12345")); // Deve falhar uma vez que já existe um usuário logado.
  } catch (ExcecaoPadrao E) {
    std::cout << E.getMensagem() << std::endl;
  }
  //===============================================================================|

  //- Criação de cargos
  //-//========================================================|
  try {
    empresa->addCargo("Vendedor");
    empresa->addCargo("Recepcionista");
    empresa->addCargo("Técnico");
    empresa->addDepartamento("Chão de fábrica");
  } catch (ExcecaoAcessoNegado E) {
    std::cout << E.resumo() << std::endl;
  }
  //===========================================================|

  // ◦Cadastrar três funcionários.
  // //==============================================|
  //
  try 
  { // 1º            |nome|       |email|            |CPF|          |Data de nascimento|
    Funcionario a("Gustavo", "gustavo@gmail.com", "16083412676",Data(2003, 03, 11, 9, 20, 30), Endereco("Rua Gonçalves Dias",846),2021013620);
  
    std::cout << "Funcionario A:"; //|> Imprime as informações do funcionário na tela.
    DisplayFuncionario(a)          //|
  
    //----------------|Funcionario||Salário||Cargo|-----|Departamento|-----|> Agora o funcionário é cadastrado no sistema.
    //                          \/  \/        \/              \/           |
    empresa->admitirFuncionario(a, 1500, "Vendedor", "Chão de fábrica"); //|
    
  } catch (ExcecaoAcessoNegado E) {std::cout << E.resumo() << std::endl;} // Caso o usuario logado nao tenha permissão para executar.
  catch (const std::exception &e) {std::cout << e.what() << std::endl;} // Caso o CPF esteja errado.

  try 
  { // 2º          |nome|       |email|          |CPF|          |Data de nascimento|
    Funcionario b("Ramon", "ramon@gmail.com", "46046903084",Data(1997, 01, 12, 8, 10, 20), Endereco("Avenida Presidente Antônio Carlos",6627), 2000012049);

    std::cout << "Funcionario B:"; //|> Imprime as informações do funcionário na tela.
    DisplayFuncionario(b)          //|

    //----------------|Funcionario||Salário||Cargo|---------|Departamento|-----|> Agora o funcionário é cadastrado no sistema.
    //                          \/  \/        \/                  \/           |
    empresa->admitirFuncionario(b, 4000, "Recepcionista","Chão de fábrica"); //|

  } catch (ExcecaoAcessoNegado E) {std::cout << E.resumo() << std::endl;} // Caso o usuario logado nao tenha permissão para executar.
  catch (const std::exception &e) {std::cout << e.what() << std::endl;} // Caso o CPF esteja errado.
  

  try 
  { // 3º             |nome|            |email|             |CPF|         |Data de nascimento|
    Funcionario c("Maria Elisa", "mariaelisa@gmail.com", "54990769600",Data(2020, 02, 10, 7, 5, 10), Endereco("Rua Augustus William Parish", 200), 2021013927);

    std::cout << "Funcionario C:"; //|> Imprime as informações do funcionário na tela.
    DisplayFuncionario(c)          //|

    //----------------|Funcionario||Salário||Cargo|---|Departamento|------|> Agora o funcionário é cadastrado no sistema.
    //                          \/  \/        \/            \/            |
    empresa->admitirFuncionario(c, 7000, "Técnico", "Chão de fábrica"); //|

  } catch (ExcecaoAcessoNegado E) {std::cout << E.resumo() << std::endl;} // Caso o usuario logado nao tenha permissão para executar.
  catch (const std::exception &e) {std::cout << e.what() << std::endl;} // Caso o CPF esteja errado.
  


  
  // ◦Cadastrar dois clientes, sendo um PF e outro PJ.
  // //==========================|
  //
  try
  { // 1º       |nome|         |email|              |CPF|       |Telefone|   |Tipo|
    Cliente A("Richarlison", "pombo@gmail.com", "35415037004", "31999255599"); // PF
    
    std::cout << "Cliente A:"; //|> Imprime as informações do funcionário na tela.
    DisplayCliente(A)          //|
      
  } catch (ExcecaoAcessoNegado E) {std::cout << E.resumo() << std::endl;} // Caso o usuario logado nao tenha permissão para Admitir um funcionário.
  catch (const std::exception &e) {std::cout << e.what() << std::endl;} // Caso o CPF esteja errado.

  try 
  { // 2º       |nome|           |email|              |CNPJ|        |Telefone|  |Tipo|
    Cliente B("Microsoft", "microsoft@gmail.com", "41283243000161","31999795555", 1); // PJ
    std::cout << "Cliente B:"; //|> Imprime as informações do funcionário na tela.
    DisplayCliente(B)          //|
      
  } catch (ExcecaoAcessoNegado E) {std::cout << E.resumo() << std::endl;} // Caso o usuario logado nao tenha permissão para Admitir um funcionário.
catch (const std::exception &e) {std::cout << e.what() << std::endl;} // Caso o CPF esteja errado.

  
  // ◦Cadastrar o produto Mesa (estoque mínimo: 20 unidades), que, para sua 
  // produção, necessita das matérias-primas e quantidades abaixo, que também
  // devem ser cadastradas. ▪ Madeira: 450g (estoque mínimo: 1 Kg) ▪ Plástico:
  // 150g (estoque mínimo: 1 Kg) ▪ Alumínio: 100g (estoque mínimo: 1 Kg) ▪
  // Parafusos: 8 unidades (estoque mínimo: 20 unidades)
//===================================|

  MateriaPrima mat[] = {MateriaPrima("Madeira", 1, "kg", 10), MateriaPrima("Plastico", 1, "kg", 10), MateriaPrima("Aluminio", 1, "kg", 10), MateriaPrima("Parafuso", 20, "unidade", 200)};

  for(int i = 0; i < 4; i++) try {empresa->addMateriaPrima(mat[i]);} catch (ExcecaoAcessoNegado E) { std::cout << E.resumo() << std::endl;}
  
  DisplayMateriaPrima((*empresa->getMateriaPrima("Madeira")))
  DisplayMateriaPrima((*empresa->getMateriaPrima("Plastico")))
  DisplayMateriaPrima((*empresa->getMateriaPrima("Aluminio")))
  DisplayMateriaPrima((*empresa->getMateriaPrima("Parafuso")))

  std::map<MateriaPrima *, double> materiais;
  materiais[empresa->getMateriaPrima("Madeira")] = 0.450;
  materiais[empresa->getMateriaPrima("Plastico")] = 0.150;
  materiais[empresa->getMateriaPrima("Aluminio")] = 0.100;
  materiais[empresa->getMateriaPrima("Parafuso")] = 8;

  try {//                       |Nome| |Materia-prima||Valor||Categoria||Lote mínimo||Estoque mínimo|
    empresa->addProduto(Produto("Mesa",   materiais  ,  120 ,  "moveis" ,     12     ,      20      ));
  } catch (ExcecaoAcessoNegado E) {std::cout << E.resumo() << std::endl;}

  //-> A seguir ocorrem muitas coisas de maneira implícita, abaixo seguem as árvores de decisões que o construtor de produto toma.
  //caminho: Produto::Produto > Produto.gerarOrdemProducao() > addOrdemProducao(o) > empresa->addOrdemProducao(o)
  //                |                       |                           |                L-> Armazena a ordem em Empresa.
  //                |                       |                           L-> Função global para evitar referência circular.
  //                |                       L-> Função que cria a ordem de produçao com o endereço de produto e a quantidade.
  //                L-> Construtor de produto verifica se já existe uma quantidade pre-determinada de produtos no estoque,
  //                caso nao tenha, ele gera uma ordem de produção passando como quantidade números múltiplos à lote_minimo.
  //
  // ◦Devem ser produzidos lotes de mesa para atender o estoque mínimo
  // -> A ordem de produção gerada é então validada:
  try {empresa->validaOrdemProducao("Mesa");} catch (const std::exception &E) {std::cout << E.what() << std::endl;} // Caso o estoque de insumos seja insuficiente.

  try
  {
    int qtd = empresa->getProduto("Mesa")->getQtd();
    std::cout << "A quantidade de Mesas agora é" << qtd << std::endl;
  } catch (const std::exception &E) {std::cout << E.what() << std::endl;}// Caso mesa não exista get("Mesa") irá falhar;

  
  // ◦Tentar excluir um funcionário cadastrado no sistema
  //
  //==========================|
  try { // Remover o primeiro funcionário da lista de funcionários
    Funcionario* j = empresa->getFuncionario("Ramon"); 
    DisplayFuncionario((*j));
    empresa->Demitir((*j));
  } catch (ExcecaoAcessoNegado E) {std::cout << E.resumo() << std::endl;} // caso ele não tenha acesso para demitir

  
  // ◦O cliente PJ deve solicitar um orçamento para aquisição de 10 mesas.
  // Em função da previsão de falta de matéria-prima, após a geração desse
  // orçamento, o preço da mesa deve sofrer um aumento de 5%. Em seguida o
  // cliente decide adquirir as 10 mesas, mesmo após o aumento.
  //==========================|
  /*std::map<Produto *, int> carrinho;

  carrinho[empresa->getProduto("Mesa")] = 10;

  try
  { 
    Cliente* c = empresa->getCliente("");
    OrcamentoVenda *orcamento = Venda_Online::getInstance().Criar_Orcamento(carrinho, c, "Dinheiro"); // Geração do orçamento

    empresa->getProduto("Mesa")->setValor(Data::dateNow(),126); // Aumento de 5% no valor do produto

    try {orcamento->Comprar();} catch (const std::exception &e) {std::cout << e.what() << std::endl;}// Tenta comprar o orçamento
    try {orcamento->Comprar(1);} catch (const std::exception &e) {std::cout << e.what() << std::endl;}// Confirma a compra do orçamento mesmo com valor alterado
    
  
  }catch (const std::exception &E) {std::cout << E.what() << std::endl;}// Caso mesa não exista get("Mesa") irá falhar;


  

  // ◦Deve ser cadastrada a rota de um veículo para transporte dos três
  // funcionários cadastrados trabalharem no turno da manhã que se inicia às 8h.
  // Devem ver exibidos os horários em que cada funcionário deverá embarcar.
  //==========================|

  std::list<Funcionario*> funcionarios_rota; //Lista de funcionarios que vao para a rota
  funcionarios_rota.push_back(empresa->getFuncionario("Gustavo"));
  funcionarios_rota.push_back(empresa->getFuncionario("Ramon"));
  funcionarios_rota.push_back(empresa->getFuncionario("Maria Elisa"));
  
  Rota R(empresa->getEndereco(), funcionarios_rota);
  Veiculo V("HDE-7041", 7);

  V.setRota(&R);

  
  for (auto it = funcionarios_rota.begin(); it != funcionarios_rota.end(); ++it){
    V.addFuncionario((*it));  
    }

  V.setHorariosEmbarque();

  std::cout << empresa->getFuncionario("Gustavo")->getHorario().getData() << std::endl;
  std::cout << empresa->getFuncionario("Ramon")->getHorario().getData() << std::endl;
  std::cout << empresa->getFuncionario("Maria Elisa")->getHorario().getData() << std::endl;
*/
  // ◦Por fim, deve-se exibir os logs de todas as operações realizadas.
  //==========================|
  Log_List::getInstance().printLogs();

  
  std::cout << "Hello World!\n";
  /**/
}