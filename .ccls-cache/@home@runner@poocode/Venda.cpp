#include "Venda.hpp"

Venda::Venda(Data data, int quantidade) {
  data_ = data;
  qnt_ = quantidade;
  }

void Venda::setData(Data data) {
    data_ = data;
}

Data Venda::getData() {
    return data_;
}
