#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string.h>


/**
 * @brief Singleton que garante que existe apenas um usuario
 */
class Usuario{
 private:
  /**
   * @brief Variável que guarda se já existe uma instância de usuário.
   */static Usuario* _instance;

  /**
   * @brief Construtor da classe.
   */Usuario();

 public:

  /**
   * @brief Função que retorna ou gera uma instância de Usuario.
   */static Usuario* getInstance();

  /**
   * @brief Função que retorna ou gera uma instância de Usuario.
   */bool checkPermissao(std::string);

};
#endif