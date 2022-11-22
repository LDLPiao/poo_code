#ifndef ORCAMENTO_H
#define ORCAMENTO_H

#include <iostream>
#include <string>
#include "Data.h"


/**
 * @brief Classe responsavel pelo armazenamento da cotação de uma determinada quantidade de produtos para um cliente
  realizado em uma data.
 */
class Orcamento{
 private:
  Data _data;

 public:
 
  Orcamento(Data data);

  /**
   * @brief Retorna o valor contido em _data.
   */
  Data getData();
  
  /**
   * @brief Atribui um valor à _data.
   * Não usar fora do construtor, já que
   * a data não muda.
   */
  void setData(Data data);


  void addPedido();
};
#endif