#ifndef ORDEM_H
#define ORDEM_H

#include <iostream>

class Ordem {
private:
/**
   * @brief Código.
   */
  int codigo_;
  
public:
/**
   * @brief Construtor da classe.
   */
  Ordem(int codigo);

/**
   * @brief Atualiza o valor do código
   */
  void setCodigo(int codigo);

/**
   * @brief Retornar o valor do código
   */
  int getCodigo();
};
#endif