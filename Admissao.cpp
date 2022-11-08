#include "Admissao.hpp"

Admissao::Admissao(Data data, double salario) {
  _data.setAMD(data);
  _salario = salario;
  }

void Admissao::setData(Data data) {
    _data = data;
}

Data Admissao::getData() {
    return _data;
}

void Admissao::setSalario(double salario) {
    _salario = salario;
}

double Admissao::getSalario() {
  return _salario;
}
