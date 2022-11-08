#ifndef ExcecaoPadrao_H
#define ExcecaoPadrao_H

#include <string.h>

class ExcecaoPadrao: public std::exception{
private:

  std::string mensagem_;
  std::string emissor_;

public:

  ExcecaoPadrao(std::string mensagem, std::string emissor);
  ExcecaoPadrao(std::string mensagem);

/**
   * @brief Retorna a mensagem da Excecao
   */final std::string getMensagem() const noexcept {return mensagem_;}

/**
   * @brief Retorna o criador da mensagem da Excecao
   */final std::string getEmissor() const noexcept {return emissor_;}
};
#endif