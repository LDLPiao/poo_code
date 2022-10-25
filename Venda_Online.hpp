#ifndef VENDA_ONLINE_H
#define VENDA_ONLINE_H

#include <list>
#include <string>
#include "Orcamento.hpp"
#include "Produto.hpp"

/**
 * @brief Singleton que garante que existe apenas uma lista de Log's
 * @author @Lucas-Emanuel
 * @example 
 */
class Venda_Online{
 private:
  /**
   * @brief Lista que armazena todos as formas de pagamento que são aceitas.
   */std::list<string> _tipos_de_pagamento;

  /**
   * @brief Lista que armazena todos os orçamentos feitos.
   */std::list<Orcamento> _orcamentos;

  /**
   * @brief Construtor da classe.
   */Venda_Online();

 public:
  
  Venda_Online(const Venda_Online&) = delete;

  /**
   * @brief Função que retorna ou gera uma instância de Venda_Online.
   */static Venda_Online& getInstance()
    {
        static Venda_Online _instance;
        return _instance;
    }

  /**
   * @brief Função que adiciona um  à Venda_Online.
   */Orcamento Criar_Orcamento(std::map<Produto*, int> carrinho)
};
#endif