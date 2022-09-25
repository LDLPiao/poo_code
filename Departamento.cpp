#include "Departamento.hpp"
#include <iostream>
#include <list>
#include <string.h>

Departamento::Departamento(std::string nome){
  nome_ = nome;
}

void Departamento::addFuncionario(*Funcionario a){
  funcionarios_.push_back(a);
}

void Departamento::removeFuncionario(*Funcionario a){
  for(auto it = funcionarios_.begin(); it != funcionarios_.end()l ++it){
    if (*it == a){ funcionarios_.erase(it++);}
  }
}