#ifndef DINHEIRO_H
#define DINHEIRO_H

#include "Data.h"
/**
 * @brief Armazena um salário com sua data.
 */
class Dinheiro{
 private:
  Data _data;
  double _valor; 
  /**
   * @brief Atribui um valor à _valor.
   * Não usar fora do construtor, já que
   * o valor não muda.
   */
  void setValor(double salario);

  /**
   * @brief Atribui um valor à _data.
   * Não usar fora do construtor, já que
   * a data não muda.
   */
  void setData(Data data);

 public:
  /**
   * @brief Construtor da classe.
   */

  Dinheiro(double dinheiro,Data data);

  /**
   * @brief Retorna o valor contido em _data.
   */
  Data getData() const;



  /**
   * @brief Retorna o valor contido em _valor.
   */
  double getValor() const;
};
#endif