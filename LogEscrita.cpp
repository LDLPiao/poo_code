#include "LogEscrita.hpp"
#include <iostream>
#include <sstream>

LogEscrita::LogEscrita(Data data, std::string entidade, Cadastro* cadastro, std::string antes, std::string depois): Log(data, entidade,cadastro){
  
    _antes = antes;
    _depois = depois;
  }

std::string LogEscrita::printLog(){
  std::stringstream log;
  log <<  getData().getData() <<": " << getCadastro() << " mudou " << getEntidade() << " de " << _antes << " para " << _depois;
  return log.str();
}
