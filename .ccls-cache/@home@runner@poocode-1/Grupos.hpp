#ifndef GRUPOS_H
#define GRUPOS_H

#include <iostream>
#include <list>
#include <string>

class Grupos {
private:
  std::list<std::string> permissoes_;
  std::string nome_;
public:
 /**
   * @brief Construtor padrao que cria o grupo de permissao
   *
   * @param nome nome do grupo
   */
  Grupos(std::string nome, std::list<std::string> permissoes);

  /**
   * @brief Adiciona uma permissão à lista de permissões do grupo
   *
   * @param a string da permissao
   */
  void addPermissao(std::string a);

  /**
   * @brief Remove uma permissão da lista de permissões do grupo
   *
   * @param a string da permissao
   */
  void removePermissao(std::string a);

  /**
   * @brief Retorna lista de permissoes
   */
  std::list<std::string> getPermissoes();

  /**
   * @brief Retorna nome do grupo
   */
  std::string getNomeGrupo();
};

#endif