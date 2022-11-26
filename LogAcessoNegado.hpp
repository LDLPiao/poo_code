#ifndef LOGACESSONEGADO_H
#define LOGACESSONEGADO_H


#include "Log.hpp"
#include "Cadastro.hpp"
#include "Data.h"
#include <iostream>
#include <list>
#include <string.h>
#include <string>

class LogAcessoNegado: public Log {
private:
  std::string funcionalidade_;
public:
 /**
   * @brief Construtor da classe.
   */

  LogAcessoNegado(Data data, std::string entidade, Cadastro* cadastro_, std::string funcionalidade);

/**
   * @brief Imprime o log
  */
  std::string printLog();

};

#endif