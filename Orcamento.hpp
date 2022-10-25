#ifndef ORCAMENTO_H
#define ORCAMENTO_H

#include <iostream>
#include <string.h>
#include "Data.h"
#include "Produto.hpp"
#include <map>
#include "PedidoCompra.hpp"

/**
 * @brief Classe responsavel pelo armazenamento da cotação de uma determinada quantidade de produtos para um cliente
  realizado em uma data.
 */
class Orcamento{
 private:
  /**
   * @brief Valor total do orçamento
   */double _valor_total;
  
  /**
   * @brief Código do produto
   */Data _data;

   

 public:

  /**
   * @brief Construtor da classe.
   */
  Orcamento()


  
 addLote(int numero_lote, int quantidade);
  void setValor(Data dia, double valor);
  void Vender(int quantidade);

};
#endif