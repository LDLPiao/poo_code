#include "Dinheiro.hpp"

Dinheiro::Dinheiro(double Dinheiro, Data data) {
  setValor(Dinheiro);
  setData(data);
}

Dinheiro::Dinheiro() {}

void Dinheiro::setData(Data data) { _data.setAMD(data); }
Data Dinheiro::getData() const { return _data; }
void Dinheiro::setValor(double valor) { _valor = valor; }
double Dinheiro::getValor() const { return _valor; }