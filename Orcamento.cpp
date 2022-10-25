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
    _valor_total += (it->first.getValor()*it->second);
}
  
}

double Orcamento::getValorTotal(){

return _valor_total;  
}