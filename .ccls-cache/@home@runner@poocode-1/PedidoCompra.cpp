#include "PedidoVenda.hpp"

PedidoVenda::PedidoVenda(Orcamento *_orcamento, Pagamento *_pagamento,
                           Data _data) {
  this->orcamento = _orcamento;
  this->pagamento = _pagamento;
  this->data = _data;
}

bool PedidoVenda::validaEstoque() {
  // TODO: Implementar o método de checagem do estoque
  return true;
}

bool PedidoVenda::validaValor() {
  // TODO: Implementar o método de comparação de valores
  return true;
}

bool PedidoVenda::validaPagamento() {
  // TODO: Implementar o método de validação da forma e do valor de pagamento
  return true;
}