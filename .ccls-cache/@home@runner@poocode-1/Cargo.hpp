#ifndef CARGO_H
#define CARGO_H

#include <iostream>
#include <list>
#include <string>

class Cargo {
private:
  std::list<int> matriculas_;
  std::string nome_;
public:
 /**
   * @brief Construtor padrao que cria o cargo
   *
   * @param nome nome do cargo
   */
  Cargo(std::string nome);

  /**
   * @brief Adiciona a matrícula de um funcionário pra lista de matrículas do cargo
   *
   * @param a numero de matricula
   */
  void addFuncionario(int a);

  /**
   * @brief Remove a matricula de um funcionário da lista de matriculas, mas primeiro confere se a matrícula está na lista
   *
   * @param a numero de matricula
   */
  void removeFuncionario(int a);

  /**
   * @brief Retorna lista de matriculas
   */
  std::list<int> getMatriculas();

  /**
   * @brief Retorna nome do cargo
   */
  std::string getNomeCargo();
};
#endif