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

  Cadastro(std::list<Grupos*> grupos): _grupos(grupos){}

  /**
   * @brief retorna a lista de grupos _grupos
   */
  std::list<Grupos*> getGrupos(){return _grupos;}
};
#endif