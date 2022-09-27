#ifndef LOTE_H
#define LOTE_H


#include "Data.h"
#include "Produto.hpp"

/**
 * @brief Esta classe e responsavel pelo armazenamento das informações referentes ao lote.
 * Ela armazenda a data, numero do lote, codigo do produto produzido no lote e quantidade de produtos produzido nesse lote.
 */
class Lote {
 public:
  /**
   * @brief Adiciona um novo pedido a lista de pedidos processados.
   * @param p Representa o novo pedido que foi recebido.
   */
  Lote(const Data& data, const long int& numero, const long int& codigo, const int& quantidade);
  

  /**
   * @brief Retorna a data do lote.*/
  Data getData() const;
  
  /**
   * @brief Retorna o numero do lote.*/
  long int getNumero() const;

  /**
   * @brief Retorna o codigo do produto do lote.*/
  long int getCodigo() const;

  /**
   * @brief Retorna a quantidade de produto do lote.*/
  int getQuantidade() const;
  
 private:
  /**
   * @brief Atributos do lote: Data, numero, codigo, quantidade de produtos do lote
   */
  Data _data;
  long int _numero;
  long int _codigo;
  int _quantidade;
};
#endif
