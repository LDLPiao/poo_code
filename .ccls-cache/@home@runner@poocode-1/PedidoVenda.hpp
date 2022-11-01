#ifndef PEDIDO_VENDA_H
#define PEDIDO_VENDA_H

#include <iostream>
#include "Data.h"
#include "Pagamento.hpp"
#include <list>

class PedidoVenda {
  private:
    /*Atributos do pedido de Venda*/
    Data _data;
    std::list<Pagamento> _pagamento;

  public:
    PedidoVenda(std::list<Pagamento> pagamento, Data data);
    /**
    *@brief: checa se existe estoque dos produtos pedidos
    *
    */
    bool validaEstoque();
    /**
    *@brief: confirma se o valor orçado corresponde ao valor atual dos produtos
    *
    */
    bool validaValor();
    /**
    *@brief: confirma que existe o pagamento no valor correto da Venda com uma forma de pagamento aceita
    *
    */
    bool validaPagamento();

};
#endif