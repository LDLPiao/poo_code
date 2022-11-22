#ifndef ORDEMCOMPRA_H
#define ORDEMCOMPRA_H

#include "Ordem.hpp"
#include <iostream> 


class OrdemCompra: public Ordem{
 private:
  /**
   * @brief 
   */int codigoMP_;

    
  /**
   * @brief quantidade
   */int quantidade_;

 public:

  /**
   * @brief Construtor da classe.
   */
  OrdemCompra(int codigo, int codigoMP, int quantidade);

  void solicitarOrcamento();

};
#endif
