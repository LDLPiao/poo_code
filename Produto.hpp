#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>
#include <map>
#include "Data.h"
#include <queue>
#include "Dinheiro.hpp"
#include "MateriaPrima.hpp"
#include <list>

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
   * @brief Lista de ponteiros de matéria prima
   */std::list<MateriaPrima*> materiaprima_;
  
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
   * @brief Número mínimo de peças no estoque
   */int _estoque_min;

   /**
   * @brief Quantidade total de produtos no estoque
   */int _qtd_total;

   /**
   * @brief Materia prima e quanto que gasta
   */std::map<MateriaPrima*,int> materiais_;

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
          std::list<MateriaPrima*> materiaprima,
          int codigo,
          double valor,
          Data dia,
          std::string categoria,
          int lote_minimo,
          int estoque_minimo,
          std::map<MateriaPrima*,int> materiais,
          int qtd = 0,
          int lote = 0);


  /**
   * @brief Retorna o valor contido em _telefone.
   * 
   */
  void addLote(int numero_lote, int quantidade);
  void setValor(Data dia, double valor);
  void Vender(int quantidade);
  Dinheiro getDinheiro(); //adicionado depois por @gustavoauler -> importante para OrcamentoVenda


  void addMP(MateriaPrima* a);
  void removeMP(MateriaPrima* a);
  std::list<MateriaPrima*> getMP();

};
#endif