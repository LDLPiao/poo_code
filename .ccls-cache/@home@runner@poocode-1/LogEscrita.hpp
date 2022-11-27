#ifndef LOGESCRITA_H
#define LOGESCRITA_H

#include "Log.hpp"

class LogEscrita: public Log {
private:
  std::string _antes;
  std::string _depois;

public:
 /**
   * @brief Construtor da classe.
   */

  LogEscrita(Data data, std::string entidade, Cadastro* cadastro, std::string antes, std::string depois);


  /**
   * @brief Imprime o Log.
   */
  std::string printLog();
};

#endif