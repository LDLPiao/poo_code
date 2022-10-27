#include "Orcamento.hpp"

Orcamento::Orcamento(Data data, std::map<Produto*, int> carrinho, Cliente &cliente){

_carrinho = carrinho;
 Orcamento::setData(data);
  _cliente = &cliente;
  
}
void Orcamento::setData(Data data) {
    _data = data;
}

Data Orcamento::getData() {
    return _data;
}

Cliente* Orcamento::getCliente() const{
  return _cliente;
}

void Orcamento::setValorTotal(){
  map<Produto*, int>::iterator it;
  _valor_total = 0;

for (it = _carrinho.begin(); it != _carrinho.end(); it++)
{
    _valor_total += (it->first.getValor()*it->second); //adicionar getValor em produto
}
  
}

double Orcamento::getValorTotal(){

return _valor_total;  
}

void Orcamento::addProduto(Produto &produto, int quantidade){

  _carrinho.insert({&produto,quantidade});
  
}
void Orcamento::addPedido(Data data, std::map<Produto*, int> carrinho, Pagamento *_pagamento, Cliente &cliente){

  Orcamento x(data, carrinho , cliente);

  PedidoCompra a(x, _pagamento, data);

  _lista_pedidos.push_back(a);
  
}
