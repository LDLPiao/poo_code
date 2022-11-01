#ifndef ORCAMENTOCOMPRA_H
#define ORCAMENTOCOMPRA_H

#include "Orcamento.hpp"
class MateriaPrima;
#include <map>

class OrcamentoCompra: public Orcamento {
private:
   std::map<MateriaPrima*, int> carrinho_;

public:
 /**
   * @brief Construtor da classe.
   */
  OrcamentoCompra(Data data, std::map<MateriaPrima*, int> carrinho);
};

#endif