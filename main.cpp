#include <iostream>
#include "Empresa.hpp"
#include "Usuario.hpp"
#include "ExcecaoPadrao.hpp"

int main() {
/*
//◦Instanciar um objeto da classe Empresa.
  Empresa* empresa = Empresa::getInstance();

// ◦Instanciar um objeto de um usuário logado que deverá ter
// permissão de acesso à todas as funcionalidades, exceto ao
// método que realiza a exclusão de um funcionário.
  std::list<std::string> permissoes;
  permissoes.push_back("Cadastrar-funcionário");
  permissoes.push_back("Cadastrar-fornecedor");
  permissoes.push_back("Cadastrar-produto");
  //- Criação de um grupo de permissão.
  //                       |nome|     |permissoes|
  empresa->cadastrarGrupo("Gerente", permissoes);
  
  permissoes.clear();
  permissoes.push_back("Gerar-orçamento");
  permissoes.push_back("Cadastrar-cliente");
  permissoes.push_back("Vender");
  empresa->cadastrarGrupo("Vendedor", permissoes);
    
  //- Criação do cadastro de um usuário.
  //                          |ID|    |senha|    |grupos|
  std::string grupos[] = {"Gerente", "Vendedor"};
  empresa->cadastrarUsuario("fulano", "12345", std::list<std::string>(std::begin(grupos), std::end(grupos)));
  
  //- Realizar o login do usuário.
  //
  try
  {
    Usuario::getInstance().Login(empresa->loginUsuario("fulano", "12345"));
  }
  catch(ExcecaoPadrao E)
  {
    std::cout << E.getMensagem() << std::endl;
  }
  
// ◦Comprovar o funcionamento do singleton do usuário logado.
// ◦Cadastrar três funcionários.
// ◦Cadastrar dois clientes, sendo um PF e outro PJ.
// ◦Cadastrar o produto Mesa (estoque mínimo: 20 unidades), que,
// para sua produção, necessita das matérias-primas e quantidades
// abaixo, que também devem ser cadastradas.
// ▪ Madeira: 450g (estoque mínimo: 1 Kg)
// ▪ Plástico: 150g (estoque mínimo: 1 Kg)
// ▪ Alumínio: 100g (estoque mínimo: 1 Kg)
// ▪ Parafusos: 8 unidades (estoque mínimo: 20 unidades)
// ◦Devem ser produzidos lotes de mesa para atender o estoque
// mínimo
// ◦Tentar excluir um funcionário cadastrado no sistema
// ◦O cliente PJ deve solicitar um orçamento para aquisição de 10
// mesas. Em função da previsão de falta de matéria-prima, após a
// geração desse orçamento, o preço da mesa deve sofrer um
// aumento de 5%. Em seguida o cliente decide adquirir as 10
// mesas, mesmo após o aumento.
// ◦Deve ser cadastrada a rota de um veículo para transporte dos três
// funcionários cadastrados trabalharem no turno da manhã que se
// inicia às 8h. Devem ver exibidos os horários em que cada
// funcionário deverá embarcar.
// ◦Por fim, deve-se exibir os logs de todas as operações realizadas.
  std::cout << "Hello World!\n";
  */
}