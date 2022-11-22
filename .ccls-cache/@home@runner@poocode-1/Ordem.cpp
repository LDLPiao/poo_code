#include "Ordem.hpp"

Ordem::Ordem(int codigo){
  codigo_ = codigo;
}

void Ordem::setCodigo(int codigo){
  codigo_ = codigo;
}

int Ordem::getCodigo(){
  return codigo_;
}
