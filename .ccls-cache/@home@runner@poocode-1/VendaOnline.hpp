#ifndef VENDA_ONLINE_H
#define VENDA_ONLINE_H

#include <list>
#include <string>
#include "Orcamento.hpp"
#include "OrcamentoVenda.hpp"
#include "Produto.hpp"

/**
 * @brief Singleton que garante que existe apenas uma lista de Log's
 * @author @Lucas-Emanuel
 * @example 
 */
class Venda_Online{
 private:

  /**
   * @brief Lista que armazena os orçamentos de venda feitos.
   */std::list<OrcamentoVenda*> _orcamentos;

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
   */OrcamentoVenda* Criar_Orcamento(std::map<Produto*, int> carrinho, Cliente* cliente, std::string forma)
    {
      OrcamentoVenda o (carrinho, cliente, forma);
      _orcamentos.push_back(&o);
      return _orcamentos.back();
    }
};
#endif