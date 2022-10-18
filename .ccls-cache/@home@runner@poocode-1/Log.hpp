#ifndef LOG_H
#define LOG_H

#include "usuario.hpp"
#include "Data.h"
#include <iostream>
#include <list>
#include <string.h>

class Log {
private:
  Data data_;
  std::string entidade_;
public:
 /**
   * @brief Construtor da classe.
   */

  Admissao(Data data, std::string entidade);

  /**
   * @brief Atribui um valor a entidade_.
   */
  void setEntidade(std::string entidade);

  /**
   * @brief Retorna o valor contido em entidade_.
   * 
   */
  std::string getEntidade();

  /**
   * @brief Atribui um valor à data_.
   * Não usar fora do construtor, já que
   * a data não muda.
   */
  void setData(Data data);

  /**
   * @brief Retorna o valor contido em data_.
   */
  Data getData();

  /**
   * @brief print do log
   */
   virtual void printLog();
};

#endif