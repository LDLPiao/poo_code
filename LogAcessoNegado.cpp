#include "LogAcessoNegado.hpp"

LogAcessoNegado::LogAcessoNegado(Data data, std::string entidade, Cadastro* cadastro, std::string funcionalidade): Log(data, entidade,cadastro){
  
    funcionalidade_ = funcionalidade;
  }
