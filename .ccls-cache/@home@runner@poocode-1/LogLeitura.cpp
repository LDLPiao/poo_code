#include "LogLeitura.hpp"
#include <string.h>
#include <iostream>

LogLeitura::LogLeitura(Data data,
                 std::string entidade,
                 Cadastro* cadastro,
                 std::string atributo)
: Pessoa(nome, email) {
  setCpf(cpf);
  setNascimento(nascimento);
  setEndereco(endereco);
  setMatricula(matricula);
  setCargo(*_cargo);
}

void LogLeitura::setAtributo(std::string atributo){atributo_ = atributo; }

std::string LogLeitura::getAtributo(){return atributo_;}
