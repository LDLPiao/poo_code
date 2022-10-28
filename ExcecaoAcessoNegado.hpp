#ifndef ExcecaoAcessoNegado_H
#define ExcecaoAcessoNegado_H

#include <string.h>
#include "LogAcessoNegado.hpp"
#include "Cadastro.hpp"
#include "Data.h"
#include <iostream>
#include "Log_List.hpp"

class ExcecaoAcessoNegado: public exception{
private:

  std::string mensagem_;
  std::string emissor_;

public:
 /**
   * @brief Construtor padrao que cria a ExcecaoAcessoNegado
   *
   * @param Mensagem de ExcecaoAcessoNegado
   */
  ExcecaoAcessoNegado(std::string mensagem, std::string emissor);
  ExcecaoAcessoNegado(std::string mensagem);


/**
   * @brief Inicializa a mensagem da ExcecaoAcessoNegado
   */

  std::string setMensagem(std::string mensagem);

/**
   * @brief Inicializa o emissor da ExcecaoAcessoNegado
   */

  std::string setEmissor(std::string emissor){emissor_ = emissor;}

/**
   * @brief Retorna a mensagem da ExcecaoAcessoNegado
   */

  std::string getMensagem() const;

/**
   * @brief Cria e retorna um log do tipo acesso negado
   */
  void criaLogExcecaoAcessoNegado(Data data, std::string entidade, Cadastro* cadastro_);
};
#endif