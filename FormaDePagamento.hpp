#ifndef FORMA_DE_PAGAMENTO_H
#define FORMA_DE_PAGAMENTO_H

#include <string>
#include <list>
#include "ExcecaoPadrao.hpp"

class FormaDePagamento {
  private:

    /**
     * @brief Variável que guarda o nome do tipo de pagamento.
     */std::string _tipo;

    /**
     * @brief Lista que armazena todos as formas de pagamento que são aceitas.
     */static std::list<std::string> _tipos_de_pagamento;

  public:

    /**
     * @brief Construtor da classe.
     */
    // FormaDePagamento(std::string tipo)
    // {
    //   for (std::list<std::string>::iterator it = _tipos_de_pagamento.begin(); it != _tipos_de_pagamento.end(); ++it)
    //   {
    //     if(tipo.compare((*it)) == 0) this->_tipo = tipo;
    //   }
    //   if(tipo.compare(_tipo) != 0)throw NULL;
    // }

    /**
     * @brief Construtor defaut.
     */FormaDePagamento(){}

    /**
     * @brief Função que adiciona um tipo válido de pagamento.
     * @example FormaDePagamento::addTipo("Dinheiro");
     */std::string getTipo(){ return _tipo;}

    /**
     * @brief Função que adiciona um tipo válido de pagamento.
     * @example FormaDePagamento::addTipo("Dinheiro");
     */static void addTipo(std::string tipo){ _tipos_de_pagamento.push_back(tipo);}

    // OPERADORES
    FormaDePagamento operator=(std::string tipo)
    {
      for (std::list<std::string>::iterator it = _tipos_de_pagamento.begin(); it != _tipos_de_pagamento.end(); ++it)
      {
        if(tipo.compare((*it)) == 0) this->_tipo = tipo;
      }
      if(tipo.compare(_tipo) != 0)throw ExcecaoPadrao {"forma de pagamento não aceita"};
      return *this;
    }
};
#endif