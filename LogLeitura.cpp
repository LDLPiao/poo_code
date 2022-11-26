#include "LogLeitura.hpp"
#include <sstream>
#include <iostream>

LogLeitura::LogLeitura(Data data, std::string entidade, Cadastro* cadastro, std::string atributo): Log(data, entidade,cadastro){
      atributo_ = atributo;
  }

void LogLeitura::setAtributo(std::string atributo){atributo_ = atributo; }

std::string LogLeitura::getAtributo(){return atributo_;}

std::string LogLeitura::printLog(){
  std::stringstream log;
  log <<  getData().getData() <<": " << getCadastro() << " leu em " << getEntidade() << " o(a) " << getAtributo();
  return log.str();
}