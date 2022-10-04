#ifndef SALARIO_H
#define SALARIO_H

#include "Data.h"
/**
 * @brief Armazena um salário com sua data.
 */
class Salario{
 private:
  Data _data;
  double _valor; 
 public:
  /**
   * @brief Construtor da classe.
   */

  Salario(double salario,Data data);

  /**
   * @brief Atribui um valor à _data.
   * Não usar fora do construtor, já que
   * a data não muda.
   */
  void setData(Data data);

  /**
   * @brief Retorna o valor contido em _data.
   */
  Data getData() const;

  /**
   * @brief Atribui um valor à _Salario.
   * Não usar fora do construtor, já que
   * o salario não muda.
   */
  void setValor(double salario);

  /**
   * @brief Retorna o valor contido em _salario.
   */
  double getValor() const;
};
#endif