#include "PedidoVenda.hpp"

PedidoVenda::PedidoVenda(std::list<Pagamento> pagamento,Data data) {
  this->_pagamento = pagamento;
  this->_data = data;
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