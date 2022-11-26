#include "LogAcessoNegado.hpp"
#include <iostream>
#include <sstream>

LogAcessoNegado::LogAcessoNegado(Data data, std::string entidade, Cadastro* cadastro, std::string funcionalidade): Log(data, entidade, cadastro){
  
    funcionalidade_ = funcionalidade;
  }

std::string LogAcessoNegado::printLog(){
  std::stringstream log;
  log <<  getData().getData() <<": " << getCadastro() << " tentou acessar " << getEntidade() << funcionalidade_;
  return log.str();
}