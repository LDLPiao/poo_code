#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include "Funcionario.hpp"
#include "Cargo.hpp"
#include "Produto.hpp"
#include "Cliente.hpp"
#include "Lote.hpp"
#include "Venda.hpp"

#include <iostream>
#include <list>
#include <string.h>

class Departamento {
private:

  std::list<Funcionario> _funcionarios;
  std::list<Cargo> _cargos;
  std::list<Produto> _produtos;
  std::list<Cliente> _clientes;
  std::list<Lote> _lotes;
  std::list<Venda> _vendas;
  
public:
 /**
   * @brief Construtor padrao que cria a empresa
   *
   * @param nome nome da empresa
   */
  Departamento(std::string nome);

  void setFuncionarios(std::list<Funcionario> funcionarios);
  void setCargos(std::list<Cargo> cargos);
  void setProdutos(std::list<Produto> produtos);
  void setClientes(std::list<Cliente> clientes);
  void setLotes(std::list<Lote> lotes);
  void setVendas(std::list<Venda> vendas);

  std::list<Funcionario> getFuncionarios();
  std::list<Cargo> getCargos();
  std::list<Produto> getProdutos();
  std::list<Cliente> getClientes();
  std::list<Lote> getLotes();
  std::list<Venda>void getVendas();

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
};

#endif
