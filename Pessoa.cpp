#include "Pessoa.hpp"



Pessoa::Pessoa(const std::string& nome,
  const std::string& email){

  this->_nome = nome;
  this->_email = email;
      
}

void Pessoa::setCpf(const std::string &certificado){
  std::string cpf = certificado;
  if (cpf.length() != 11){
  std::cout << "CPF INVALIDO" << std::endl;
  return;
}
  //Verifica primeiro digito, resto deve ser igual ao penultimo digito
  char n;
  int soma = 0;
  int n1;
  
  for(int i = 0; i < 9; i++){
    n = cpf[i];
    n1 = n - '0';
    soma = soma + n1*(10-i);
  }
  
  soma = soma*10;
  int resto = soma%11;
  if (resto == 10)
    resto = 0;
 

  //Verifica o segundo digito
  char m;
  int soma2 = 0;
  int m1;

  for(int i = 0; i < 10; i++){
    m = cpf[i];
    m1 = m - '0';
    soma2 = soma2 + m1*(11-i);
  }

  
  soma2 = soma2*10;
  int resto2 = soma2%11;
  if (resto2 == 10)
    resto2 = 0;
  
  
  int d1 = cpf[9] - '0';
  int d2 = cpf[10] - '0';
  
  if(resto == d1 && resto2 == d2)
    this->_certificado = certificado;
  else
    std::cout << "CPF INVALIDO" << std::endl;
    
    
}

void Pessoa::setCNPJ(const std::string &certificado){
  std::string cnpj = certificado;

  if (cnpj.length() != 14){
  std::cout << "CNPJ INVALIDO" << std::endl;
  return;
    }
//Verifica primeiro digito
int n[14];
    
for(int i = 0; i < 14; i++){
n[i] = cnpj[i] - '0';
}
n[0] = n[0]*5;
n[1] = n[1]*4;
n[2] = n[2]*3;
n[3] = n[3]*2;
n[4] = n[4]*9;
n[5] = n[5]*8;
n[6] = n[6]*7;
n[7] = n[7]*6;
n[8] = n[8]*5;
n[9] = n[9]*4;
n[10] = n[10]*3;
n[11] = n[11]*2;

int soma1 = 0;
  
for(int i = 0; i < 12; i++){
soma1 = soma1 + n[i];
}

int resto1;
int verificador1;

resto1 = soma1%11;

if(resto1 < 2)
  verificador1 = 0;
else
  verificador1 = 11 - resto1;

if(verificador1 != n[12]){
  std::cout << "CNPJ INVALIDO" << std::endl;
  return;
}
//Verifica o segundo digito

for(int i = 0; i < 14; i++){
n[i] = cnpj[i] - '0';
}

n[0] = n[0]*6;
n[1] = n[1]*5;
n[2] = n[2]*4;
n[3] = n[3]*3;
n[4] = n[4]*2;
n[5] = n[5]*9;
n[6] = n[6]*8;
n[7] = n[7]*7;
n[8] = n[8]*6;
n[9] = n[9]*5;
n[10] = n[10]*4;
n[11] = n[11]*3;
n[12] = n[12]*2;

int soma2 = 0;
  
for(int i = 0; i < 13; i++){
soma2 = soma2 + n[i];
}

int resto2;
int verificador2;

resto2 = soma2%11;

if(resto2 < 2)
  verificador2 = 0;
else
  verificador2 = 11 - resto2;

if(verificador2 == n[13]){
  this->_certificado = certificado;
  }
else
  std::cout << "CNPJ INVALIDO" << std::endl;
  
  
}



std::string Pessoa::getNome() const{
  return this->_nome;
}
std::string Pessoa::getEmail() const{
  return this->_email;
}
std::string Pessoa::getCertificado() const{
  return this->_certificado;
}

bool Pessoa::operator<(const Pessoa &outro){
  if(this->getNome().compare(outro.getNome()) < 0) return true;
  else return false;
}

bool Pessoa::operator>(const Pessoa &outro){
  if(this->getNome().compare(outro.getNome()) > 0) return true;
  else return false;
}

bool Pessoa::operator=(const Pessoa &outro){
  if (this->getNome().compare(outro.getNome()) == 0) return true;
  else return false;
}
