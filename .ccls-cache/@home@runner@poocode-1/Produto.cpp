#include "Produto.hpp"
#include <queue>
#include <iostream>
#include "Data.h"
#include "Dinheiro.hpp"



Produto::Produto(std::string nome,
                std::list<MateriaPrima*> materiaprima,
                int codigo,
                double valor,
                Data dia,
                std::string categoria,
                int lote_minimo,
                int estoque_minimo,
                std::map<MateriaPrima*,int> materiais,
                int qtd,
                int lote)
: _nome(nome), _codigo(codigo), _categoria(categoria),
  _lote_min(lote_minimo), _estoque_min(estoque_minimo)
{
    if(qtd != 0 && lote != 0) addLote(lote, qtd);
    setValor(dia, valor);
    materiais_ = materiais;
    materiaprima_ = materiaprima;
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
    if(quantidade > this->_qtd_total) throw Excessao_Venda_Nao_Autorizada{};

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

void Produto::addMP(MateriaPrima* a){
  materiaprima_.push_back(a);
}
void Produto::removeMP(MateriaPrima* a){
    for(auto it = materiaprima_.begin(); it != materiaprima_.end(); ++it){
    if (*it == a){ 
      materiaprima_.erase(it++);
    }
  }
}

std::list<MateriaPrima*> Produto::getMP(){ return materiaprima_; }