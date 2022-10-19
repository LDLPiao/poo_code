#ifndef USUARIO_H
#define USUARIO_H

#include <list>
#include "Log.hpp"

/**
 * @brief Singleton que garante que existe apenas uma lista de Log's
 * @author @Lucas-Emanuel
 * @example LogLeitura a("Parâmetros");
 *          Log_List::getInstance().addLog(&a);
 */
class Log_List{
 private:

  /**
   * @brief Set de permissões que o usuário logado possui.
   */std::list<Log*> _lista;

  /**
   * @brief Construtor da classe.
   */Log_List();

 public:
  
  Log_List(const Log_List&) = delete;

  /**
   * @brief Função que retorna ou gera uma instância de Log_List.
   */static Log_List& getInstance()
   {
      static Log_List _instance;
      return _instance;
   }

  /**
   * @brief Função que adiciona Log à Log_List.
   */void addLog(Log* log){_lista.push_back(log);}
};
#endif