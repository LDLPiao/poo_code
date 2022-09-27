#include "Pessoa.hpp"



Pessoa::Pessoa(const std::string& nome,
  const std::string& email){

  this->_nome = nome;
  this->_email = email;
      
}

void Pessoa::setCpf(const long int &certificado){
  long int certificado_mod = certificado;
  
  if (certificado == 0)
    std::cout<<"CPF Invalido"<<std::endl;
        
    
  int count = 0;
  while (certificado_mod != 0) {
        certificado_mod = certificado_mod / 10;
        ++count;
    }
  if(count == 11)
  this->_certificado = certificado;
  else
  std::cout << "CPF invalido" << std::endl;
}

void Pessoa::setCNPJ(const long int &certificado){
  long int certificado_mod = certificado;
  
  if (certificado == 0)
    std::cout<<"CNPJ Invalido"<<std::endl;
        
    
  int count = 0;
  while (certificado_mod != 0) {
        certificado_mod = certificado_mod / 10;
        ++count;
    }
  if(count == 14)
  this->_certificado = certificado;
  else
  std::cout << "CNPJ invalido" << std::endl;
}

std::string Pessoa::getNome() const{
  return this->_nome;
}
std::string Pessoa::getEmail() const{
  return this->_email;
}
long int Pessoa::getCertificado() const{
  return this->_certificado;
}

bool Pessoa::operator<(const Pessoa &outro){
  (this->getNome().compare(outro.getNome()) < 0) ? return true : return false;
}

bool Pessoa::operator>(const Pessoa &outro){
  (this->getNome().compare(outro.getNome()) > 0) ? return true : return false;
}

bool Pessoa::operator=(const Pessoa &outro){
  (this->getNome().compare(outro.getNome()) == 0) ? return true : return false;
}