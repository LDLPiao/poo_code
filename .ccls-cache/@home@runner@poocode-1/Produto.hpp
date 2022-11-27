#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>
#include <map>
#include "Data.h"
#include <queue>
#include "Dinheiro.hpp"
#include "MateriaPrima.hpp"
#include "OrdemProducao.hpp"
#include <list>

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de um cliente.
 */
class Produto{
 private:
  /**
   * @brief codigo mais recente dos produtos
   */static int _ultimo_codigo;

  /**
   * @brief Nome do produto
   */std::string _nome;

  /**
   * @brief Lista de ponteiros de matéria prima
   */std::map<MateriaPrima*,double> materiaprima_;
  
  /**
   * @brief Código do produto
   */int _codigo;

   /**
   * @brief Valor do produto
   */Dinheiro _valor;

   /**
   * @brief Categoria do produto
   */std::string _categoria;

   /**
   * @brief Número mínimo de produção em um lote
   */int _lote_min;

    /**
   * @brief Número atual do lote
   */int _lote;


   /**
   * @brief Número mínimo de peças no estoque
   */int _estoque_min;

   /**
   * @brief Quantidade total de produtos no estoque
   */int _qtd_total = 0;

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
          std::map<MateriaPrima*,double> materiaprima,
          double valor,
          std::string categoria,
          int lote_minimo,
          int estoque_minimo,
          int qtd = 0,
          int lote = 0);

  void addLote(int numero_lote, int quantidade);
  void setValor(Data dia, double valor);
  void Vender(int quantidade);
  Dinheiro getDinheiro(); //adicionado depois por @gustavoauler -> importante para OrcamentoVenda

  int getLote(){return _lote;}
  int getLoteMin(){return _lote_min;}
  int getCodigo(){return _codigo;}
  int getQtd(){return _qtd_total;}
  int getEstoqueMin(){return _estoque_min;}
  std::string getNome(){return _nome;}

  void gerarOrdemProducao(int qtd);
  void subtrairMateriaPrima(int qtd);

  std::map<MateriaPrima*,double> getMP(){ return materiaprima_; }
  void addMP(MateriaPrima* a);
  void removeMP(MateriaPrima* a);


};
#endif