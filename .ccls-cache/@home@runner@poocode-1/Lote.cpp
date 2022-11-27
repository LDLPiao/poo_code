#include "Lote.hpp"

int Lote::_ultimo_codigo = 0;

Lote::Lote(const Data& data, const int& codigo, const int& quantidade): _data(data){
  this->_codigo = codigo;
  this->_quantidade = quantidade;
  
  _numero = _ultimo_codigo;
  _ultimo_codigo++;
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

