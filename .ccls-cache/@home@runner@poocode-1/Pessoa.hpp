#ifndef PESSOA_H
#define PESSOA_H


#include <iostream>
#include <string.h>

class Pessoa {
 public:
  /**
   * @brief Adiciona um novo cadastro de pessoa
   * @param Nome utilizado no cadastro.
   * @param Email  utilizado no cadastro.
   */
  Pessoa(const std::string& nome,
        const std::string& email);
        

  /**
   * @brief inicializa o CPF do cadastrado.*/
  void setCpf(const long int &certificado);

  /**
   * @brief inicializa o CNPJ do cadastrado.*/
  void setCNPJ(const long int &certificado);

  /**
   * @brief Retorna o nome do cadastrado.*/
  std::string getNome() const;
  
  /**
   * @brief Retorna o email do cadastrado.*/
  std::string getEmail() const;

  /**
   * @brief Retorna o certificado do cadastrado.*/
  long int getCertificado() const;

  /**
   * @brief Retorna a pessoa com nome menor, em ordem alfabética.*/
  bool operator<(const Pessoa &outro);

 private:
  /**
   * @brief Container que armazena o nome, email e certificado da pessoa(CPF ou CNPJ)
   */
  std::string _nome;
  std::string _email;
  long int _certificado;
};
#endif
