#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string.h>
#include <set>
#include <list>

/**
 * @brief Singleton que garante que existe apenas um usuario
 */
class Usuario{
 private:
  /**
   * @brief Variável que guarda se já existe uma instância de usuário.
   */static Usuario* _instance;

  /**
   * @brief Lista de permissões que o usuário logado possui.
   */std::set<std::string> _permissoes;

  /**
   * @brief Construtor da classe.
   */Usuario();

 public:

  /**
   * @brief Função que retorna ou gera uma instância de Usuario.
   * @param Grupos_de_permissão, list que contem os nomes de todos os grupos no qual o usuario pertence.
   */static Usuario* getInstance(std::list<std::string>);

  /**
   * @brief Função que retorna se o usuário possui uma permissão específica.
   */bool checkPermissao(std::string);

  /**
   * @brief Função que processa e armazena todas as permissões que o usuario possui.
   */void carregaPermissao(std::list<std::string>);

  /**
   * @brief Função que limpa todas as permissões que  um usuário tem.
   */void limpaPermissao(){ this->_permissoes.clear();}

};
#endif