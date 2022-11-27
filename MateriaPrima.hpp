#ifndef MATERIAPRIMA_H
#define MATERIAPRIMA_H

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include "Data.h"
#include "ExcecaoPadrao.hpp"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de um cliente.
 */

class MateriaPrima{
 private:
  /**
   * @brief Código da ultima matéria prima
   */static int _ultimo_codigo;

  /**
   * @brief Nome da Matéria Prima
   */std::string _nome;

  /**
   * @brief Código da Matéria Prima
   */int _codigo;

   /**
   * @brief Unidade da Matéria Prima (Ex.: kg, m)
   */std::string _unidade;

   /**
   * @brief Número mínimo de peças no estoque
   */int _estoque_min;

   /**
   * @brief Quantidade total de insumos no estoque
   */int _qtd;

 public:

  /**
   * @brief Construtor da classe.
   */
  MateriaPrima(std::string nome,
                int estoque_minimo,
                std::string unidade,
                int qtd = 0);
  std::string getNome(){return _nome;}
  int getCodigo(){return _codigo;}
  std::string getUnidade(){return _unidade;}
  int getEstoqueMin(){return _estoque_min;}
  int getQtd(){return _qtd;}
  void removeQtd(int qtd)
  {
    if(_qtd < qtd) throw ExcecaoPadrao("Estoque de Materia Prima insuficiente");
    _qtd -= qtd;
  }
};
#endif