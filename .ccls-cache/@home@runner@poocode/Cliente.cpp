#include "Cliente.hpp"
#include <string.h>
#include <iostream>

Cliente::Cliente(std::string nome,
                 std::string email,
                 const long int certificado,
                 const int telefone,
                 bool tipo)
: Pessoa(nome, email), _tipo(tipo), _telefone(telefone)
{
  if(tipo)  setCNPJ(certificado);
    else setCpf(certificado);
}

void Cliente::setTipo(bool tipo){_tipo = tipo;}

bool Cliente::getTipo(){return _tipo;}

void Cliente::setTelefone(int telefone){_telefone = telefone;}

int Cliente::getTelefone(){return _telefone;}
