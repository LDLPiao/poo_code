#ifndef VENDA_ONLINE_H
#define VENDA_ONLINE_H

#include <list>
#include "Log.hpp"

/**
 * @brief Singleton que garante que existe apenas uma lista de Log's
 * @author @Lucas-Emanuel
 * @example LogLeitura a("Parâmetros");
 *          Venda_Online::getInstance().addLog(&a);
 */
class Venda_Online{
 private:
  /**
   * @brief Lista que armazena todos as formas de pagamento que são aceitas.
   */

  /**
   * @brief Lista que armazena todos os orçamentos feitos.
   */

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
   * @brief Função que adiciona Log à Venda_Online.
   */
};
#endif