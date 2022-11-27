#include "MateriaPrima.hpp"

int MateriaPrima::_ultimo_codigo = 0;

MateriaPrima::MateriaPrima(std::string nome,
              int estoque_minimo,
              std::string unidade,
              int qtd){
  _nome = nome;
  _codigo = _ultimo_codigo;
  _ultimo_codigo++;
  _estoque_min = estoque_minimo;
  _unidade = unidade;
  _qtd = qtd;
  }