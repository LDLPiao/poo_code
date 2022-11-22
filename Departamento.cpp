#include "Departamento.hpp"
#include <iostream>
#include <list>
#include <string>

Departamento::Departamento(std::string nome){
  nome_ = nome;
}

void Departamento::addFuncionario(Funcionario* a){
  funcionarios_.push_back(a);
}

void Departamento::removeFuncionario(Funcionario* a){
  for(auto it = funcionarios_.begin(); it != funcionarios_.end(); ++it){
    if (*it == a){ 
      funcionarios_.erase(it++);
    }
  }
}

void Departamento::demitirFuncionario(Funcionario* a){
  for(auto it = funcionarios_.begin(); it != funcionarios_.end(); ++it){
    if (*it == a){ 
      funcionarios_.erase(it++);
      a->Demitir();
    }
  }
}

void Departamento::admitirFuncionario(Funcionario* a, const double salario, Cargo &cargo){
  funcionarios_.push_back(a);
  a->Admitir(salario, cargo, (*this));
}

std::list<Funcionario*> Departamento::getFuncionarios() { return funcionarios_; }

std::string Departamento::getNomeDepartamento() { return nome_; }