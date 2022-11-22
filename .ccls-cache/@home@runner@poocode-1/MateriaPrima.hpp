#ifndef MATERIAPRIMA_H
#define MATERIAPRIMA_H

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include "Data.h"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de um cliente.
 */

class MateriaPrima{
 private:
  /**
   * @brief Nome da Matéria Prima
   */std::string _nome;
  
  /**
   * @brief Código da Matéria Prima
   */const int _codigo;

   /**
   * @brief Unidade da Matéria Prima (Ex.: kg, m)
   */std::string _unidade;

   /**
   * @brief Número mínimo de peças no estoque
   */int _estoque_min;

   /**
   * @brief Quantidade total de produtos no estoque
   */int _qtd;

 public:

  /**
   * @brief Construtor da classe.
   */
  MateriaPrima(std::string nome,
              int codigo,
              int estoque_minimo,
              int qtd = 0);

  void checkEstoque(int numero_lote, int quantidade);
  void setValor(Data dia, double valor);
  void Vender(int quantidade);

};
#endif