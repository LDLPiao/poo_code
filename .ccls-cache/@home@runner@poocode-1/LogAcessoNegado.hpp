#ifndef LOGACESSONEGADO_H
#define LOGACESSONEGADO_H


#include "Log.hpp"
#include "Cadastro.hpp"
#include "Data.h"
#include <iostream>
#include <list>
#include <string.h>

class LogAcessoNegado: public Log {
private:
  std::string funcionalidade_;
public:
 /**
   * @brief Construtor da classe.
   */

  LogAcessoNegado(Data data, std::string entidade, Cadastro* cadastro_, std::string funcionalidade);

  /**
   * @brief Atribui um valor a Funcionalidadwe.
   */
  void setFuncionalidade(std::string funcionalidade);

  /**
   * @brief Retorna o valor contido em Funcionalidade.
   * 
   */
  std::string getFuncionalidade();

};

#endif