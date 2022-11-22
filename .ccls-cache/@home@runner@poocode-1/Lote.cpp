#include "Lote.hpp"


Lote::Lote(const Data& data, const long int& numero, const long int& codigo, const int& quantidade): _data(data){
    this->_numero = numero;
    this->_codigo = codigo;
    this->_quantidade = quantidade;
}




Data Lote::getData() const{
  return this->_data;
}


long int Lote::getNumero() const{
  return this->_numero;
}

long int Lote::getCodigo() const{
  return this->_codigo;
}

int Lote::getQuantidade() const{
  return this->_quantidade;
}

