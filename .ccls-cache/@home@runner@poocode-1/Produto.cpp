#include "Produto.hpp"
#include <queue>
#include <iostream>
#include <map>
#include "Data.h"
#include "Dinheiro.hpp"
#include "ExcecaoPadrao.hpp""

void addOrdemProducao(OrdemProducao o);

int Produto::_ultimo_codigo = 0;

Produto::Produto(std::string nome,
          std::map<MateriaPrima*,double> materiaprima,
          double valor,
          std::string categoria,
          int lote_minimo,
          int estoque_minimo,
          int qtd,
          int lote)
: _nome(nome), _categoria(categoria),
  _lote_min(lote_minimo), _estoque_min(estoque_minimo)
{
    
  if(qtd != 0 && lote != 0) addLote(lote, qtd);
  setValor(Data::dateNow(), valor);

  if(_qtd_total < _estoque_min)
  {
    int qtd = _qtd_total;
    while(qtd < _estoque_min) qtd += _lote_min;
    gerarOrdemProducao(qtd - _qtd_total);
  }

  materiaprima_.swap(materiaprima);
  _codigo = Produto::_ultimo_codigo;
  Produto::_ultimo_codigo++;
}

void Produto::gerarOrdemProducao(int qtd)
{
  OrdemProducao o (this, qtd);
  addOrdemProducao(o);
}

void Produto::subtrairMateriaPrima(int qtd)
{
  for(auto it = materiaprima_.begin(); it != materiaprima_.end(); it++){
    it->first->removeQtd(it->second * qtd);
  }
}

void Produto::addLote(int numero_lote, int quantidade)
{
  this->_qtd_total += quantidade;
  this->_qtd_por_lote.push(std::make_pair(quantidade, numero_lote));
}

void Produto::setValor(Data dia, double valor)
{
    this->_valor.setValor(valor);
}

Dinheiro Produto::getDinheiro(){
  return this->_valor;
}

void Produto::Vender(int quantidade)
{
    if(quantidade > this->_qtd_total) throw  ExcecaoPadrao ("Quantidade insuficiente de produto para venda");

    if(this->_qtd_por_lote.back().first > 0)
    {
        this->_qtd_por_lote.back().first --;
        this->_qtd_total--;
    }
    else
    {
        this->_qtd_por_lote.pop();
        this->_qtd_por_lote.back().first --;
        this->_qtd_total--;
    }
    if (quantidade > 0)this->Vender(quantidade-1);
}