#ifndef VENDA_H
#define VENDA_H

#include "Data.h"
#include "Cliente.hpp"
#include "Lote.hpp"
class Produto;
class Cliente;

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * da venda.
 */
class Venda{
 private:
  Data data_;
  int qnt_;
  int loteNum_;
  Cliente* cliente_;

 public:
  /**
   * @brief Construtor da classe.
   */

  Venda(Data data, int quantidade, Cliente &cliente);

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
/**
   * @brief Retorna o valor contido em qnt_.
   */
  
  Data getQnt();

  /**
   * @brief Ponteiro para o produto da Venda
   */
  Produto* produto_;

  /**
   * @brief Retorna o produto da venda
   */
  Produto* getProduto() const;

  /**
   * @brief Atualiza o produto da venda
   * @param Novo produto
   */
  void setProduto(Produto &produto);

  /**
   * @brief Atualiza o numero do lote de produção.
   */
  Data setLoteNum(int num);

  /**
   * @brief Retorna o valor atual do lote de produção.
   */
  Data getLoteNum(); 

  /**
   * @brief Retorna o ponteiro de Cliente
   */
  Cliente* getCliente() const;

};
#endif