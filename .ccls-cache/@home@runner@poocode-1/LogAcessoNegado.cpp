#include "LogAcessoNegado.hpp"

LogAcessoNegado::LogAcessoNegado(Data data, std::string entidade, Cadastro* cadastro, std::string funcionalidade): Log(data, entidade,cadastro){
  
    
    funcionalidade_ = funcionalidade;
  }

   void LogAcessoNegado::setFuncionalidade(std::string funcionalidade){
     
     funcionalidade_ = funcionalidade;
     
   }
  std::string LogAcessoNegado::getFuncionalidade(){
    
  return this->funcionalidade_;
  
}