#include "Pagamento.hpp"

Pagamento::Pagamento() {
  data_ = nullptr;
  tipo = nullptr;
  parcelamento_ = 0;
  valor_ = 0;
}

Pagamento::Pagamento(std::string tipo, int parcelamento, Data data, double valor) {
  data_ = data;
  setTipo(tipo);
  parcelamento_ = parcelamento;
  valor_ = valor;
}

void Pagamento::setData(Data data) {
    data_ = data;
}

Data Pagamento::getData() {
    return data_;
}

void Pagamento::setParcelamento(int parcelamento){
  parcelamento_ = parcelamento;
}

int Pagamento::getParcelamento(){
  return parcelamento_;
}

void Pagamento::setTipo(std::string tipo){
  tipo_ = tipo;
}

std::string Pagamento::getTipo(){
  return tipo_;
}

void Pagamento::setValor(int valor){
  valor_ = valor;
}

double Pagamento::getValor(){
  return valor_;
}
