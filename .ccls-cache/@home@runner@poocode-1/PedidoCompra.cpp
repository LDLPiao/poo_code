#include "PedidoCompra.hpp"

PedidoCompra::PedidoCompra(Orcamento *_orcamento, Pagamento *_pagamento,
                           Data _data) {
  this->orcamento = _orcamento;
  this->pagamento = _pagamento;
  this->data = _data;
}

bool PedidoCompra::validaEstoque() {
  // TODO: Implementar o método de checagem do estoque
  return true;
}

bool PedidoCompra::validaValor() {
  // TODO: Implementar o método de comparação de valores
  return true;
}

bool PedidoCompra::validaPagamento() {
  // TODO: Implementar o método de validação da forma e do valor de pagamento
  return true;
}