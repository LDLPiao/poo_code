#include "Venda.hpp"

Venda::Venda(Data data, int quantidade, int numerolote) {
  data_ = data;
  qnt_ = quantidade;
  loteNum_ = numerolote;
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

Produto* getProduto() const{
    return produto_;
}

void setProduto(Produto &produto){
    produto_ = produto;
}

Data setLoteNum(int num){
  loteNum_ = num;
}

Data getLoteNum(){
  return loteNum_;
}

