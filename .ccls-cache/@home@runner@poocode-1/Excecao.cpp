#include "Excecao.hpp"

Excecao::Excecao(std::string mensagem){
  mensagem_ = mensagem;
}
std::string Excecao::setMensagem(std::string mensagem){
  this->mensagem_ = mensagem;
}

std::string Excecao::getMensagem() const{
  return this->mensagem_;
}
void Excecao::criaLogExcecao(Data data, std::string entidade, Cadastro* cadastro_){
  LogAcessoNegado a(data, entidade, cadastro_, Excecao::getMensagem());
  Log_List::getInstance().addLog(a);
}


  

