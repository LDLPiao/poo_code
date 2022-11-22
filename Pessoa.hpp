#ifndef PESSOA_H
#define PESSOA_H


#include <iostream>
#include <string>

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
  void setCpf(const std::string &certificado);

  /**
   * @brief inicializa o CNPJ do cadastrado.*/
  void setCNPJ(const std::string &certificado);

  /**
   * @brief Retorna o nome do cadastrado.*/
  std::string getNome() const;
  
  /**
   * @brief Retorna o email do cadastrado.*/
  std::string getEmail() const;

  /**
   * @brief Retorna o certificado do cadastrado.*/
  std::string getCertificado() const;

  /**
   * @brief Retorna se a pessoa tem nome menor, em ordem alfabética.*/
  bool operator<(const Pessoa &outro);
  
  /**
   * @brief Retorna se a pessoa tem nome maior, em ordem alfabética.*/
  bool operator>(const Pessoa &outro);

  /**
   * @brief Retorna as pessoas tem mesmo nome.*/
  bool operator=(const Pessoa &outro);


 private:
  /**
   * @brief Container que armazena o nome, email e certificado da pessoa(CPF ou CNPJ)
   */
  std::string _nome;
  std::string _email;
  std::string _certificado;
};
#endif
