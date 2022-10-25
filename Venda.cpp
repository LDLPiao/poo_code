#include "Venda.hpp"

Venda::Venda(Data data, int quantidade, Cliente &cliente) {
  data_ = data;
  qnt_ = quantidade;
  loteNum_ = 0;
  cliente_ = &cliente;
}

void Venda::setData(Data data) {
    data_ = data;
}

Data Venda::getData() {
    return data_;
}

Data Venda::getQnt() {
    return qnt_;
}

Produto* Venda::getProduto() const{
    return produto_;
}

void Venda::setProduto(Produto &produto){
    produto_ = &produto;
}

Data Venda::setLoteNum(int num){
  loteNum_ = num;
}

Data Venda::getLoteNum(){
  return loteNum_;
}

Cliente* Venda::getCliente() const{
  return cliente_;
}
