#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string.h>
#include <map>
#include "Data.h"
#include <queue>
#include "Dinheiro.hpp"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de um cliente.
 */
class Produto{
 private:
  /**
   * @brief Nome do produto
   */std::string _nome;
  
  /**
   * @brief Código do produto
   */int _codigo;

   /**
   * @brief Valor do produto
   */Dinheiro _valor(double dinheiro,Data data);

   /**
   * @brief Categoria do produto
   */std::string _categoria;

   /**
   * @brief Número mínimo de produção em um lote
   */int _lote_min;

   /**
   * @brief Número mínimo de peças no estoque
   */int _estoque_min;

   /**
   * @brief Quantidade total de produtos no estoque
   */int _qtd_total;

   /**
   * @brief Quantidade de produtos por lote
   * @param First -> quantidade
   * @param Second -> lote
   */std::queue<std::pair<int,int>> _qtd_por_lote;

 public:

  struct Excessao_Venda_Nao_Autorizada {};

  /**
   * @brief Construtor da classe.
   */
  Produto(std::string nome,
          int codigo,
          double valor,
          Data dia,
          std::string categoria,
          int lote_minimo,
          int estoque_minimo,
          int qtd = 0,
          int lote = 0);


  /**
   * @brief Retorna o valor contido em _telefone.
   * 
   */
  void addLote(int numero_lote, int quantidade);
  void setValor(Data dia, double valor);
  void Vender(int quantidade);

};
#endif