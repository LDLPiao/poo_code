#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include "Pessoa.hpp"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de um cliente.
 */
class Cliente: public Pessoa {
 private:
  /**
   * @brief Booleando que mostra se o cliente é PJ ou PF
   */
  bool _tipo;

  /**
   * @brief Endereco de telefone do cliente
   */
  std::string _telefone;
 public:

  /**
   * @brief Construtor da classe.
   */

  Cliente(std::string nome,
          std::string email,
          std::string certificado,
          std::string telefone,
          bool tipo = 0);

  Cliente();

  /**
   * @brief Atribui um valor à _tipo.
   * True => Pessoa jurídica
   * False => Pessoa Física
   */
  void setTipo(bool tipo);

  /**
   * @brief Retorna o valor contido em _tipo.
   */
  bool getTipo();

  /**
   * @brief Atribui um valor à _telefone.
   */
  void setTelefone(std::string telefone);

  /**
   * @brief Retorna o valor contido em _telefone.
   * 
   */
  std::string getTelefone();

};
#endif