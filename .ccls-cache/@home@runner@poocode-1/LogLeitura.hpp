#ifndef LOGLEITURA_H
#define LOGLEITURA_H

#include <iostream>
#include <string.h>
#include "Log.hpp"

class LogLeitura: public Log {
 private:
  /**
   * @brief Booleando que mostra se o cliente é PJ ou PF
   */
  std::string atributo_;
 public:

  /**
   * @brief Construtor da classe.
   */

  LogLeitura(Data data, std::string entidade, Cadastro* cadastro, std::string atributo);

  /**
   * @brief Retorna o valor contido em atributo_.
   */
  std::string getAtributo();
  /**
   * @brief Muda o nome contido em atributo_.
   */
  void setAtributo(std::string atributo);

};
#endif