
#include "Orcamento.hpp"

Orcamento::Orcamento(): _data(Data::dateNow()){}

void Orcamento::setData(Data data) {
    this->_data = data;
}

Data Orcamento::getData() {
    return _data;
}