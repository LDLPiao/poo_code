
#include "Orcamento.hpp"

Orcamento::Orcamento(Data data){
  this->_data = data;
}
void Orcamento::setData(Data data) {
    this->_data = data;
}

Data Orcamento::getData() {
    return _data;
}