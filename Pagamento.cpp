#include "Pagamento.hpp"

Pagamento::Pagamento(std::string tipo, int parcelamento, Data data, double valor){
  data_ = data;
  parcelamento_ = parcelamento;
  valor_ = valor;
  try 
  {
    tipo_ = tipo;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
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

std::string Pagamento::getTipo(){
  return tipo_.getTipo();
}

void Pagamento::setValor(int valor){
  valor_ = valor;
}

double Pagamento::getValor(){
  return valor_;
}
