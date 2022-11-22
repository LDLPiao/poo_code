#include "Funcionario.hpp"

#include <iostream>

Funcionario::Funcionario(const std::string nome, const std::string email,
                         const string cpf, const Data nascimento,
                         const std::string endereco, const int matricula, const Cargo & cargo, std::pair<float,float> coordenadas, Data horario)
    : Pessoa(nome, email) {
  setCpf(cpf);
  setNascimento(nascimento);
  setEndereco(endereco);
  setMatricula(matricula);
  setCargo(*_cargo);
  setCoordenadas(coordenadas);
  setHorario(horario);
}

Data Funcionario::getNascimento() const { return _nascimento; }

std::string Funcionario::getEndereco() const { return _endereco; }

int Funcionario::getMatricula() const { return _matricula; }

list<Dinheiro> Funcionario::getRegistroDinheiro() const {
  return _registro_salario;
}

list<Admissao> Funcionario::getAdmissoes() const { return _admissoes; }

list<Data> Funcionario::getDemissoes() const { return _demissoes; }

double Funcionario::getDinheiroatual() const { return _registro_salario.back().getValor(); }

Cargo *Funcionario::getCargo() const { return _cargo; }

Departamento *Funcionario::getDepartamento() const { return _departamento; }

void Funcionario::setNascimento(Data nascimento) {
  _nascimento = nascimento;
}

void Funcionario::setEndereco(const std::string endereco) {
  _endereco = endereco;
}

void Funcionario::setMatricula(const int matricula) { _matricula = matricula; }

void Funcionario::setCargo(Cargo &cargo) { _cargo = &cargo; }

void Funcionario::setDepartamento(Departamento &departamento) {
  _departamento = &departamento;
}

void Funcionario::addSalario(const double salario) {
  Dinheiro novo(salario, Data::dateNow());
  _registro_salario.push_back(novo);
}

void Funcionario::Admitir(const double salario, Cargo &cargo,
                          Departamento &departamento) {
  getAdmissoes().push_back({Data::dateNow(), salario});
  setCargo(cargo);
  setDepartamento(departamento);
}

void Funcionario::Demitir() {
  getDemissoes().push_back(Data::dateNow());
  addSalario(0);
  _cargo = nullptr;
  _departamento = nullptr;
}

void Funcionario::Promover(const double salario, Cargo &cargo,
                           Departamento &departamento) {
  addSalario(salario);
  setCargo(cargo);
  setDepartamento(departamento);
}

void Funcionario::setHorario(Data horario){
  horario_.setHora(horario.getHora());
  horario_.setMin(horario.getMin());
}

void Funcionario::setCoordenadas (std::pair<float,float> coordenadas){
  coordenadas_.first = coordenadas.first;
  coordenadas_.second = coordenadas.second;
}

std::pair<float,float> Funcionario::getCoordenadas() const { return coordenadas_; }