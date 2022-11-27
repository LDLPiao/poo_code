#include "Cliente.hpp"
#include <string>
#include <iostream>

Cliente::Cliente(std::string nome,
                 std::string email,
                 std::string certificado,
                 std::string telefone,
                 bool tipo)
: Pessoa(nome, email), _tipo(tipo), _telefone(telefone)
{
  if(tipo)  setCNPJ(certificado);
    else setCpf(certificado);
}

void Cliente::setTipo(bool tipo){_tipo = tipo;}

bool Cliente::getTipo(){return _tipo;}

void Cliente::setTelefone(std::string telefone){_telefone = telefone;}

std::string Cliente::getTelefone(){return _telefone;}
