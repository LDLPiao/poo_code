#include "Log.hpp"

Log::Log(Data data, std::string entidade, Cadastro* &cadastro) {
    data_ = data;
    entidade_ = entidade;
    cadastro_ = cadastro;
  }

void Log::setData(Data data) {
    data_ = data;
}

Data Log::getData() {
    return data_;
}

void Log::setEntidade(std::string entidade) {
    entidade_ = entidade;
}

std::string Log::getEntidade() {
  return entidade_;
}

Cadastro* Log::getCadastro() {
    return cadastro_;
}

void Log::setCadastro(Cadastro &cadastro) { cadastro_ = &cadastro; }

