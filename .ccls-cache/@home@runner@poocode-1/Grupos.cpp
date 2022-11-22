#include "Grupos.hpp"

#include <iostream>
#include <list>
#include <string>

Grupos::Grupos(std::string nome, std::list<std::string> permissoes): nome_(nome), permissoes_(permissoes){}

void Grupos::addPermissao(std::string a){
  permissoes_.push_back(a);
}

void Grupos::removePermissao(std::string a){
  for(auto it = permissoes_.begin(); it != permissoes_.end(); ++it){
    if (*it == a){ permissoes_.erase(it++);}
  }
}

std::list<std::string> Grupos::getPermissoes() { return permissoes_; }

std::string Grupos::getNomeGrupo() { return nome_; }