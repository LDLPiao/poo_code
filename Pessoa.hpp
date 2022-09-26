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
  void setCpf(const int &certificado);

  /**
   * @brief inicializa o CNPJ do cadastrado.*/
  void setCNPJ(const int &certificado);

  /**
   * @brief Retorna o nome do cadastrado.*/
  std::string getNome() const;
  
  /**
   * @brief Retorna o email do cadastrado.*/
  std::string getEmail() const;

  /**
   * @brief Retorna o certificado do cadastrado.*/
  int getCertificado() const;

 private:
  /**
   * @brief Verifica se o CNPJ e o CPF passa em todas as restricoes
   *
   * @param certificado que sera verificado
   * @return true Verdadeiro se passa em todas as condicoes
   * @return false Falso se nao passa em pelo menos uma das condicoes
   */
  bool verificaCertificado(long int certificado, const bool pessoa_juridica);

 private:
  /**
   * @brief Container que armazena o nome, email e certificado da pessoa(CPF ou CNPJ)
   */
  std::string _nome;
  std::string _email;
  int _certificado;
};
#endif
