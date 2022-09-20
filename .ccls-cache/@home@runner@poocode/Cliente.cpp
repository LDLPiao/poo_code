#include "Cliente.hpp"
#include <string.h>
#include <iostream>

Cliente::Cliente(std::string nome,
                 std::string email,
                 const int certificado,
                 const int telefone,
                 bool tipo)
: Pessoa(nome, email), _tipo(tipo), _telefone(telefone)
{
  if(tipo)  setCNPJ(certificado);
    else setCpf(certificado);
}


