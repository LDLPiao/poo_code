#ifndef USUARIO_H
#define USUARIO_H

#include "Grupos.hpp"
#include "Cadastro.hpp"
#include <iostream>
#include <string>
#include <set>
#include <list>

/**
 * @brief Singleton que garante que existe apenas um usuario
 */
class Usuario{
 private:

  /**
   * @brief Set de permissões que o usuário logado possui.
   */std::set<std::string> _permissoes;

  /**
   * @brief Construtor da classe.
   */Usuario(){}

 public:

  /**
   * @brief Função que retorna ou gera uma instância de Usuario.
   */static Usuario& getInstance()
    {
        static Usuario _instance;
        return _instance;
    }

  /**
   * @brief Função que retorna ou gera uma instância de Usuario.
   * @param Grupos_de_permissão, list que contem os nomes de todos os grupos no qual o usuario pertence.
   */void Login(Cadastro*);

  /**
   * @brief Função que retorna se o usuário possui uma permissão específica.
   */bool checkPermissao(std::string);

  /**
   * @brief Função que processa e armazena todas as permissões que o usuario possui.
   */void carregaPermissao(std::list<Grupos*>);

  /**
   * @brief Função que limpa todas as permissões que  um usuário tem.
   */void limpaPermissao(){ this->_permissoes.clear();}

};
#endif