#include "Veiculo.hpp"

float Veiculo::velocidade = 18;

Veiculo::Veiculo(std::string _placa, int _capacidade) {
  this->placa = _placa;
  this->capacidade = _capacidade;
}

std::string Veiculo::getPlaca() { return placa; }

int Veiculo::getCapacidade() { return capacidade; }

float Veiculo::getVelocidade() { return velocidade; }

Rota* Veiculo::getRota() { return rota; }

void Veiculo::setRota(Rota* _rota) { this->rota = _rota; }

bool Veiculo::checkCapacidade(int qtd) {
  // Recupera o tamanho da lista funcionarios
  int _size = funcionarios.size();

  if (_size + qtd > capacidade) {
    return false;
  }
  return true;
}

void Veiculo::addFuncionario(Funcionario *funcionario) {
  if (checkCapacidade(1)) {
    funcionarios.push_back(funcionario);
  }
  // TODO: Jogar excessão quando não houver vagas para o funcionário
}

void Veiculo::removeFuncionario(Funcionario *funcionario) {
  list<Funcionario *>::iterator it;
  it = std::find(funcionarios.begin(), funcionarios.end(), funcionario);
  if (it != funcionarios.end()) {
    funcionarios.erase(it);
  }
  // TODO: jogar excessão caso não seja encontrado o funcionário na lista
}