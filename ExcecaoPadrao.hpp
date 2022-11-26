#ifndef ExcecaoPadrao_H
#define ExcecaoPadrao_H

#include <string>
//#include <ostream>
//#include <iostream>

class ExcecaoPadrao: public std::exception{
private:

  std::string mensagem_;
  std::string emissor_;

public:

  ExcecaoPadrao(std::string mensagem, std::string emissor = "defaut"): mensagem_(mensagem), emissor_(emissor) {}

  /**
   * @brief Retorna a mensagem da Excecao
   */std::string getMensagem() const noexcept {return mensagem_;}

  /**
   * @brief Retorna o criador da mensagem da Excecao
   */std::string getEmissor() const noexcept {return emissor_;}

   const char* what() const noexcept {return mensagem_.c_str();}
};

// inline std::ostream& operator<<(std::ostream &Saida,const ExcecaoPadrao &E)
// {
//   std::cout << "|Excecao| -Mensagem: " << E.getMensagem() << " | -Emissor: " << E.getEmissor();
//   return Saida;
// }

#endif