#include "Funcionario.hpp"

#include <iostream>
#include "LogEscrita.hpp"
#include "LogList.hpp"
#include "Usuario.hpp"

Funcionario::Funcionario(const std::string nome, const std::string email,
                         const string cpf, const Data nascimento,
                        Endereco endereco, const int matricula)
    : Pessoa(nome, email), _endereco(endereco) {
  setCpf(cpf);
  setNascimento(nascimento);
  //setEndereco(endereco);
  setMatricula(matricula);
  //setCoordenadas(coordenadas);
}

Data Funcionario::getNascimento() const { return _nascimento; }

Endereco Funcionario::getEndereco() const { return _endereco; }

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

// void Funcionario::setEndereco(Endereco endereco) {
//   _endereco = endereco;
// }

void Funcionario::setMatricula(const int matricula) { _matricula = matricula; }

void Funcionario::setCargo(Cargo &cargo) { _cargo = &cargo; }

void Funcionario::setDepartamento(Departamento &departamento) {
  _departamento = &departamento;
}

void Funcionario::addSalario(const double salario) {
  Dinheiro novo(salario, Data::dateNow());
  _registro_salario.push_back(novo);
}

void Funcionario::Admitir(const double salario, Cargo &cargo, Departamento &departamento) {
  //LogEscrita(Data data, std::string entidade, Cadastro* cadastro, std::string antes, std::string depois);
  LogEscrita *a  = new LogEscrita(Data::dateNow(), "Funcionario", Usuario::getInstance().getCadastro(), "", cargo.getNomeCargo());
  Log_List::addLog(a);
  
  LogEscrita *b = new LogEscrita(Data::dateNow(), "Funcionario", Usuario::getInstance().getCadastro(), "", departamento.getNomeDepartamento());
  Log_List::addLog(b);
  
  getAdmissoes().push_back({Data::dateNow(), salario});
  setCargo(cargo);
  setDepartamento(departamento);
}

void Funcionario::Demitir() {
  LogEscrita *a  = new LogEscrita(Data::dateNow(), "Funcionario", Usuario::getInstance().getCadastro(), "", Data::dateNow().getData());
  Log_List::addLog(a);
  LogEscrita *b = new LogEscrita(Data::dateNow(), "Funcionario", Usuario::getInstance().getCadastro(), to_string(getDinheiroatual()), "0");
  Log_List::addLog(b);
  
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

// void Funcionario::setCoordenadas (std::pair<float,float> coordenadas){
//   coordenadas_.first = coordenadas.first;
//   coordenadas_.second = coordenadas.second;
// }

// std::pair<float,float> Funcionario::getCoordenadas() const { return coordenadas_; }

Data Funcionario::getHorario() const { return horario_; }