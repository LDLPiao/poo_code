#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include "Funcionario.hpp"
#include <iostream>
#include <list>
#include <string.h>

class Departamento {
private:
  std::list<*Funcionario> funcionarios_;
  std::string nome_;
public:
 /**
   * @brief Construtor padrao que cria o departamento
   *
   * @param nome nome do departamento
   */
  Departamento(std::string nome);

  /**
   * @brief Adiciona um funcionário pra lista de funcionarios do departamento
   *
   * @param a ponteiro para o funcionário desejado
   */
  void addFuncionario(*Funcionario a);

  /**
   * @brief Remove um funcionário da lista de funcionarios do departamento, mas primeiro confere se o funcionário está na lista
   *
   * @param a ponteiro para o funcionário desejado
   */
  void removeFuncionario(*Funcionario a);
};

#endif
