#include "Cargo.hpp"

#include <iostream>
#include <list>
#include <string>

Cargo::Cargo(std::string nome){
  nome_ = nome;
}

void Cargo::addFuncionario(int a){
  matriculas_.push_back(a);
}

void Cargo::removeFuncionario(int a){
  for(auto it = matriculas_.begin(); it != matriculas_.end(); ++it){
    if (*it == a){ matriculas_.erase(it++);}
  }
}

std::list<int> Cargo::getMatriculas() { return matriculas_; }

std::string Cargo::getNomeCargo() { return nome_; }