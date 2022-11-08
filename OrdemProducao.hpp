#ifndef ORDEMPRODUCAO_H
#define ORDEMPRODUCAO_H

#include "Ordem.hpp"
#include <iostream> 


class OrdemProducao: public Ordem{
 private:

 public:

  /**
   * @brief Construtor da classe.
   */
  OrdemCompra(int codigo);

  bool checkMateriaPrima();


};
#endif
