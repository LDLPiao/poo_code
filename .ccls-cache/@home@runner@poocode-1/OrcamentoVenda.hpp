#ifndef ORCAMENTOVENDA_H
#define ORCAMENTOVENDA_H

#include <iostream> //ok
#include <string.h> //ok
#include "Data.h" //ok
#include "Produto.hpp" //ok
#include <map> //ok
#include "PedidoVenda.hpp" //ok
#include "Cliente.hpp" //ok
#include "Orcamento.hpp" //ok
#include <string>
#include "FormaDePagamento.hpp"

#define ESTOU_CIENTE true

/**
 * @brief Classe responsavel pelo armazenamento da cotação de uma determinada quantidade de produtos para um cliente
  realizado em uma data.
 */
class OrcamentoVenda: public Orcamento{
 private:
  /**
   * @brief Valor total do orçamento DE Venda
   */double _valor_total;

  /**
   * @brief forma de pagamento;
   */FormaDePagamento _forma;
    
  /**
   * @brief Código do produto
   */std::map<Produto*, int> _carrinho;
  
  /**
   * @brief Ponteiro para o Cliente
   */Cliente* _cliente;

  /**
   * @brief Lista de pedidos
   */std::list<PedidoVenda> _lista_pedidos;

 public:

  /**
   * @brief Construtor da classe.
   */
  OrcamentoVenda(std::map<Produto*, int> carrinho, Cliente* cliente, std::string forma_de_pagamento);

  /**
   * @brief Retorna o valor contido em _valor_total.
   */double getValorTotal();
  
  /**
   * @brief Retorna o valor contido em _valor_total.
   */double ValorTotal();

  /**
   * @brief Retorna o ponteiro de Cliente
   */Cliente* getCliente() const;

  
  /**
   * @brief Adiciona o produto e sua quantidade ao orçamento de Venda
   */void addProduto(Produto &produto, int quantidade);
  
  /**
   * @brief Criar um pedido de compra e armazena-lo dentro da lista de pedidos do orcamento
   */void addPedido(Data data, std::list<Pagamento> pagamento);

  /**
   * @brief Retorna o ponteiro de Cliente
   */void Comprar(bool ciente = 0);
};
#endif
