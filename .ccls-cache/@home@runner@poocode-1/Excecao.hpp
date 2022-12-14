#ifndef EXCECAO_H
#define EXCECAO_H

#include <string.h>
#include "LogAcessoNegado.hpp"
#include "Cadastro.hpp"
#include "Data.h"
#include <iostream>
#include "Log_List.hpp"

class Excecao {
private:

  std::string mensagem_;
  std::string emissor_;

public:
 /**
   * @brief Construtor padrao que cria a excecao
   *
   * @param Mensagem de excecao
   */
  Excecao(std::string mensagem, std::string emissor);
  Excecao(std::string mensagem);


/**
   * @brief Inicializa a mensagem da excecao
   */

  std::string setMensagem(std::string mensagem);

/**
   * @brief Inicializa o emissor da excecao
   */

  std::string setEmissor(std::string emissor){emissor_ = emissor;}

/**
   * @brief Retorna a mensagem da excecao
   */

  std::string getMensagem() const;

/**
   * @brief Cria e retorna um log do tipo acesso negado
   */
  void criaLogExcecao(Data data, std::string entidade, Cadastro* cadastro_);
};
#endif