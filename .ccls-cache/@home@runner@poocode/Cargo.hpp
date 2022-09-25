#ifndef CARGO_H
#define CARGO_H

#include <iostream>
#include <list>
#include <string.h>

class Departamento {
private:
  std::list<Funcionario*> cargos_;
  std::string nome_;
public:
 /**
   * @brief Construtor padrao que cria o cargo
   *
   * @param nome nome do cargo
   */
  Departamento(std::string nome);

  /**
   * @brief Adiciona um funcionário para a lista de funcionários no cargo
   *
   * @param a ponteiro para o funcionário desejado
   */
  void addFuncionario(*Funcionario a);

  /**
   * @brief Remove um funcionário da lista de funcionarios do cargo, mas primeiro confere se o funcionário está na lista
   *
   * @param a ponteiro para o funcionário desejado
   */
  void removeFuncionario(*Funcionario a);
};

#endif