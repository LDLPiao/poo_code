#ifndef USUARIO_H
#define USUARIO_H

#include "Pessoa.h"
#include "Data.h"
#include <string>

/**
 * @brief Classe que armazena e gerencia as informacoes do funcionário.
 *
 */
class Usuario {
 public:
  /**
   * @brief Construtor padrao que inicializa todas as variaveis privadas da
   * classe.
   *
   * @param login Login do usuario
   * @param password Password do usuario
   */
  Usuario(const std::string nome, const std::string email, const int cpf, const );

  /**
   * @brief Retorna o login do usuario
   *
   * @return std::string Login do usuario
   */
  std::string getLogin() const;

  /**
   * @brief Retorna o password do usuario
   *
   * @return std::string Password do usuario
   */
  std::string getPassword() const;

  /**
   * @brief Atualiza o login do usuario
   *
   * @param login Novo login do usuario
   */
  void setLogin(const std::string& login);

  /**
   * @brief Atualiza o password do usuario
   *
   * @param login Novo password do usuario
   */
  void setPassword(const std::string& password);

 private:
  /**
   * @brief Login do usuario
   *
   */
  // TODO: declare aqui o login do usuario

  /**
   * @brief Password do usuario
   *
   */
  // TODO: declare aqui o password do usuario
};

#endif