#ifndef CADASTRO_H
#define CADASTRO_H

#include "Grupos.hpp"

#include <iostream>
#include <string>
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
  std::string _ID;
  std::string _senha;

 public:

  Cadastro(std::string ID, std::string senha, std::list<Grupos*> grupos): _grupos(grupos), _ID(ID), _senha(senha){}

  /**
   * @brief retorna a lista de grupos _grupos
   */
  std::list<Grupos*> getGrupos(){return _grupos;}
  std::string getID(){return _ID;}
  std::string getSenha(){return _senha;}
};
#endif