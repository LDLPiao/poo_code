#include <iostream>
#include "Empresa.hpp"
#include "Usuario.hpp"
#include "Cadastro.hpp"

int main() {
//◦Instanciar um objeto da classe Empresa.
  Empresa* empresa = Empresa::getInstance();

// ◦Instanciar um objeto de um usuário logado que deverá ter
// permissão de acesso à todas as funcionalidades, exceto ao
// método que realiza a exclusão de um funcionário.
  
  Usuario* usuario = &Usuario::getInstance();
  
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
}