#include "Excecao.hpp"

Excecao::Excecao(std::string mensagem){
  mensagem_ = mensagem;
}
std::string Excecao::setMensagem(mensagem) const{
  this->mensagem_ = mensagem;
}

std::string Excecao::getMensagem() const{
  return this->mensagem_;
}
LogAcessoNegado Excecao::criaLogExcecao(Data data, std::string entidade , Cadastro* cadastro_, Excecao excecao){

LogAcessoNegado x (data, entidade, cadastro_, excecao.getMensagem());
  return x;
  
}
