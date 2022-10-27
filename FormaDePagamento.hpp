#ifndef FORMA_DE_PAGAMENTO_H
#define FORMA_DE_PAGAMENTO_H

#include <string>
#include <list>

class FormaDePagamento {
  private:

    /**
     * @brief Variável que guarda o nome do tipo de pagamento.
     */std::string _tipo;

    /**
     * @brief Lista que armazena todos as formas de pagamento que são aceitas.
     */static std::list<string> _tipos_de_pagamento;

  public:

    /**
     * @brief Construtor da classe.
     */FormaDePagamento(std::string tipo)
      {
        for (std::list<std::string>::iterator it = _tipos_de_pagamento.begin(); it != _tipos_de_pagamento.end(); ++it)
        {
          if(_tipo.strcompare(*it));
        }
      }
};
#endif