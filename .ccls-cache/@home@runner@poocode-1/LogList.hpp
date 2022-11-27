#ifndef LOG_LIST_H
#define LOG_LIST_H

#include <list>
#include "Log.hpp"

/**
 * @brief Singleton que garante que existe apenas uma lista de Log's
 * @author @Lucas-Emanuel
 * @example LogLeitura* a = new LogLeitura("Parâmetros");
 *          Log_List::addLog(a);
 */
class Log_List{
 private:

  /**
   * @brief Set de permissões que o usuário logado possui.
   */static std::list<Log*> _lista;

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

  ~Log_List()
  {
    for (std::list<Log*>::iterator it = _lista.begin(); it != _lista.end(); ++it)
    {
      delete (*it);
    }
  }

  /**
   * @brief Função que adiciona Log à Log_List.
   */static void addLog(Log* log){_lista.push_back(log);}

  /**
   * @brief Função que adiciona Log à Log_List.
   */static void printLogs()
   {
      for (std::list<Log*>::iterator it = _lista.begin(); it != _lista.end(); ++it)
      {
        (*it)->printLog();
      }
   }

};
#endif