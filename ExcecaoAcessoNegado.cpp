#include "ExcecaoAcessoNegado.hpp"
#include "LogAcessoNegado.hpp"
#include "LogList.hpp"

ExcecaoAcessoNegado::ExcecaoAcessoNegado(std::string mensagem){
  mensagem_ = mensagem;
}
ExcecaoAcessoNegado::ExcecaoAcessoNegado(std::string mensagem, std::string emissor){
  mensagem_ = mensagem;
  emissor_ = emissor;
}
void ExcecaoAcessoNegado::setMensagem(std::string mensagem){
  this->mensagem_ = mensagem;
}

std::string ExcecaoAcessoNegado::getMensagem() const{
  return this->mensagem_;
}
void ExcecaoAcessoNegado::criaLogExcecaoAcessoNegado(Data data, std::string entidade, Cadastro* cadastro_){
  LogAcessoNegado a(data, entidade, cadastro_, this->getMensagem());
  //Log_List::addLog(a);
}


  

