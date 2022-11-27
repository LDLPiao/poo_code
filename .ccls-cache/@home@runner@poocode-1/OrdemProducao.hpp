#ifndef ORDEMPRODUCAO_H
#define ORDEMPRODUCAO_H

#include "Ordem.hpp"
#include <iostream>

class Produto;

class OrdemProducao: public Ordem{
 private:

  Produto* _produto;
  int _qtd;

 public:

  /**
   * @brief Construtor da classe.
   */
  OrdemProducao(Produto* produto, int qtd, int codigo = 0): Ordem(codigo), _produto(produto), _qtd(qtd){}

  Produto* getProduto(){return _produto;}
  int getQtd(){return _qtd;}

};
#endif
