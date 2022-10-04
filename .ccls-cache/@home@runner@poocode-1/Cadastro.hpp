#ifndef CADASTRO_H
#define CADASTRO_H

#include "Grupos.hpp"

#include <iostream>
#include <string.h>
/**
   * @brief Cadastros
*/
class Cadastro{
 private:
  /**
   * @brief lista de ponteiro para os grupos de permissão  
   * que está incluso
   */
  std::list<Grupos*> _grupos;

 public:
  /**
   * @brief retorna a lista de grupos _grupos
   */
  std::list<Grupos*> getGrupos();
}