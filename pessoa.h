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
   * @param Certificado utilizado no cadastro.
   */
  Pessoa(const std::string& nome,
        const std::string& email,
        const int certificado,
        const bool pessoa_juridica);//cpf = 0,cnpj = 1


  
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
   * @param certificado_ que sera verificado
   * @return true Verdadeiro se passa em todas as condicoes
   * @return false Falso se nao passa em pelo menos uma das condicoes
   */
  bool checkCertificado(const std::string& certificado) const;

 private:
  /**
   * @brief Container que armazena o nome, email e certificado da pessoa(CPF ou CNPJ)
   */
  std::string nome_;
  std::string email_;
  int certificado_;
};
#endif
