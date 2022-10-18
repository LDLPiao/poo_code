#ifndef EXCECAO_H
#define EXCECAO_H

#include <string.h>
#include "LogAcessoNegado"
#include "Log.hpp"
#include "Cadastro.hpp"
#include "Data.h"
#include <iostream>



class Excecao {
private:

  std::string mensagem_;

public:
 /**
   * @brief Construtor padrao que cria a excecao
   *
   * @param Mensagem de excecao
   */
  Excecao(std::string mensagem);


/**
   * @brief Inicializa a mensagem da excecao
   */

  std::string setMensagem(std::string mensagem);
/**
   * @brief Retorna a mensagem da excecao
   */

  std::string getMensagem() const;

/**
   * @brief Cria e retorna um log do tipo acesso negado
   */
  LogAcessoNegado criaLogExcecao(Data data, std::string entidade, Cadastro* cadastro_, std::string funcionalidade);
  
};
#endif