#ifndef PEDIDO_VENDA_H
#define PEDIDO_VENDA_H

#include <iostream>
#include "Data.h"
#include "Orcamento.hpp"
#include "Pagamento.hpp"

class PedidoVenda {
  private:
    /*Atributos do pedido de Venda*/
    Data data;
    Orcamento* orcamento;
    Pagamento* pagamento;

  public:
    PedidoVenda(Orcamento* _orcamento, Pagamento* _pagamento, Data _data);
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