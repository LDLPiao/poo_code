#ifndef ORCAMENTO_H
#define ORCAMENTO_H

#include <iostream>
#include <string.h>
#include "Data.h"
#include "Produto.hpp"
#include <map>
#include "PedidoCompra.hpp"
#include "Cliente.hpp"
class Produto;


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
   */
  Data _data;
    
  /**
   * @brief Código do produto
   */
  std::map<Produto*, int> _carrinho;
  
  /**
   * @brief Ponteiro para o Cliente
   */
  Cliente* _cliente;

 public:

  /**
   * @brief Construtor da classe.
   */
  Orcamento(Data data, std::map<Produto*, int> carrinho, Cliente &cliente);

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

  /**
   * @brief Retorna o valor contido em _valor_total.
   */
  double getValorTotal();
  
  /**
   * @brief Retorna o valor contido em _valor_total.
   */
  void setValorTotal();
  
  

  /**
   * @brief Retorna o ponteiro de Cliente
   */
  Cliente* getCliente() const;

  

void addProduto(Produto &produto, int quantidade);
  
/**
   * @brief Criar um pedido de compra e armazena dentro do orçamento
   */
void addPedido();



};
#endif