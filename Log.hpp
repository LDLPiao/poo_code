#ifndef LOG_H
#define LOG_H

#include "Cadastro.hpp"
#include "Data.h"
#include <iostream>
#include <list>
#include <string>

class Log {
private:
  Data data_;
  std::string entidade_;
  Cadastro* cadastro_;
public:
 /**
   * @brief Construtor da classe.
   */

  Log(Data data, std::string entidade, Cadastro* &cadastro);
  Log(){}

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

  Cadastro* getCadastro();
  void setCadastro(Cadastro &cadastro);

  /**
   * @brief print do log
   */
  //virtual std::string printLog() = 0;
};

#endif