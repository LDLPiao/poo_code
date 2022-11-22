#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include "Data.h"
#include "FormaDePagamento.hpp"
#include <iostream>
#include <list>
#include <string>

class Pagamento {
  private:
  FormaDePagamento tipo_; // Tipo de pagamento
  int parcelamento_;
  Data data_;
  double valor_;
  public:
   /**
   * @brief Construtor padrao que cria o pagamento
   *
   * @param 
   */
  Pagamento(std::string tipo, int parcelamento, Data data, double valor);

  /**
   * @brief Atribui um valor à data_.
   * Não usar fora do construtor, já que
   * a data não muda.
   */
  void setData(Data data);
  /**
   * @brief Retorna o valor contido em data_.
   */
  Data getData();

  /**
   * @brief Atribui um valor à parcelamento_.
   */
  void setParcelamento(int parcelamento);
  /**
   * @brief Retorna o valor contido em parcelamento_.
   */
  int getParcelamento();

  /**
   * @brief Retorna o valor contido em tipo_.
   */
  std::string getTipo();

  /**
   * @brief Atribui um valor à valor_.
   */
  void setValor(int valor);
  
  double getValor();

};
#endif