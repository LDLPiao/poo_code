#include "Cargo.hpp"
#include <iostream>
#include <list>
#include <string.h>

Cargo::Cargo(std::string nome){
  nome_ = nome;
}

void Cargo::addFuncionario(*Funcionario a){
  cargos_.push_back(a);
}

void Cargo::removeFuncionario(*Funcionario a){
  for(auto it = cargos_.begin(); it != cargos_.end()l ++it){
    if (*it == a){ cargos_.erase(it++);}
  }
}