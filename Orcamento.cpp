#include "Orcamento.hpp"

Orcamento::Orcamento(Data data){
  _data = data;
}
void Orcamento::setData(Data data) {
    _data = data;
}

Data Orcamento::getData() {
    return _data;
}