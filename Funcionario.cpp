#include "Funcionario.hpp"

#include <iostream>

Funcionario::Funcionario(const std::string nome, const std::string email,
                         const int cpf, const Data nascimento,
                         const std::string endereco, const int matricula)
    : Pessoa(nome, email) {
      
    }

Data Funcionario::getNascimento() const{
  return _nascimento;
}

std::string Funcionario::getEndereco() const{
  return _endereco;
}

int Funcionario::getMatricula() const{
  return _matricula;
}

list<double> Funcionario::getRegistroSalario() const{
  return _registro_salario;
}

list<Admissao> Funcionario::getAdmissoes() const{
  return _admissoes;
}

list<Data> Funcionario::getDemissoes() const{
  return _demissoes;
}

double Funcionario::getSalarioatual() const{
  return _registro_salario.back();
}

Cargo* Funcionario::getCargo() const{
  return _cargo;
}

Departamento* Funcionario::getDepartamento() const{
  return _departamento;
}

void Funcionario::setNascimento(const Data nascimento){
  _nascimento = nascimento;
}

void Funcionario::setEndereco(const std::string endereco){
  _endereco = endereco;
}

void Funcionario::setMatricula(const int matricula){
  _matricula = matricula;
}

void Funcionario::setRegistroSalario(const list<double> registro_salario){
  _registro_salario = registro_salario;
}

void Funcionario::setCargo(Cargo &cargo){
  _cargo = &cargo;
}

void Funcionario::setDepartamento(Departamento &departamento){
  _departamento = &departamento;
}

void Funcionario::addSalario(const double salario){
  _registro_salario.push_back(salario);
}

void Funcionario::Admitir(const double salario, Cargo &cargo, Departamento &departamento){
  Data aux;
  getAdmissoes().push_back({aux.dateNow(), salario});
  setCargo(cargo);
  setDepartamento(departamento);
}

void Funcionario::Demitir(){
  Data aux;
  getDemissoes().push_back(aux.dateNow());
  addSalario(0);
  _cargo = nullptr;
  _departamento = nullptr;
}

void Funcionario::Promover(const double salario, Cargo &cargo, Departamento &departamento){
  addSalario(salario);
  setCargo(cargo);
  setDepartamento(departamento);
}