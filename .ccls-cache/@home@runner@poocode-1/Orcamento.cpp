#include "Orcamento.hpp"

Orcamento::Orcamento(std::map<Produto*, int> carrinho){

_carrinho = carrinho;
  
}
void Orcamento::setData(Data data) {
    _data = data;
}