#include "Pessoa.hpp"



Pessoa::Pessoa(const std::string& nome,
  const std::string& email){

  this->_nome = nome;
  this->_email = email;
      
}

void Pessoa::setCpf(const int &certificado){
  if(verificaCertificado(certificado, 0) == 1)
  this->_certificado = certificado;
  else
  std::cout << "CPF invalido" << std::endl;
}

void Pessoa::setCNPJ(const int &certificado){
  if(verificaCertificado(certificado, 1) == 1)
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
int Pessoa::getCertificado() const{
  return this->_certificado;
}

bool verificaCertificado(int certificado, const bool pessoa_juridica){
  

    if (certificado == 0)
        return 0;
    
  int count = 0;
    while (certificado != 0) {
        certificado = certificado / 10;
        ++count;
    }
    
  
  if(pessoa_juridica == 0 && count == 11){
    return 1;
    }
  else if(pessoa_juridica == 1 && count == 14){
    return 1;
    }
  else {
    return 0;
    }
    
  } 
}
