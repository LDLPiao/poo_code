#include "OrdemCompra.hpp"

#include <iostream>


OrdemCompra::OrdemCompra(int codigo, int codigoMP, int quantidade): Ordem(codigo){
  codigoMP_ = codigoMP;
  quantidade_ = quantidade;
}


