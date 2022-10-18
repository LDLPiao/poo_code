#ifndef USUARIO_H
#define USUARIO_H

#include <string.h>
#include <set>
#include <list>
#include "Log.hpp"

/**
 * @brief Singleton que garante que existe apenas um usuario
 */
class Log_List{
 private:
  /**
   * @brief Variável que guarda se já existe uma instância de usuário.
   */static Log_List* _instance;

  /**
   * @brief Set de permissões que o usuário logado possui.
   *///std::set<std::string> _permissoes;

  /**
   * @brief Construtor da classe.
   */Log_List();

 public:

  /**
   * @brief Função que retorna ou gera uma instância de Log_List.
   */static Log_List* getInstance();

  /**
   * @brief Função que adiciona Log à Log_List.
   */void addLog(Log);
};
#endif