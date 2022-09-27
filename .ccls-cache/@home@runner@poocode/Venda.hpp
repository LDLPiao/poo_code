#ifndef VENDA_H
#define VENDA_H

#include "Data.h"
#include "Cliente.hpp"
#include "Produto.hpp"
#include "Lote.hpp"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * da venda.
 */
class Venda{
 private:
  Data data_;
  int qnt_;
 public:

  /**
   * @brief Construtor da classe.
   */

  Admissao(Data data, int quantidade);

  /**
   * @brief Atribui um valor à _data.
   * Não usar fora do construtor, já que
   * a data não muda.
   */
  void setData(Data data);

  /**
   * @brief Retorna o valor contido em _data.
   */
  Data getData();

};
#endif