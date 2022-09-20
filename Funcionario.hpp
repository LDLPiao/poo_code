#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Pessoa.hpp"
#include "Data.hpp"
#include <string>
#include <list>

/**
 * @brief Classe que armazena e gerencia as informacoes do funcionário.
 *
 */
class Funcionario: public Pessoa {

 private:
  /**
   * @brief Data de nascimento
   */
  Data _nascimento;

  /**
   * @brief Endereço
   */
  string _endereco;

 public:
  /**
   * @brief Construtor padrao que inicializa todas as variaveis privadas da
   * classe.
   *
   * @param login Login do usuario
   * @param password Password do usuario
   */
  Funcionario(const std::string nome, const std::string email, const int cpf, const Data nascimento, const std::string endereco, const int matricula): Pessoa(nome, email);

  /**
   * @brief Retorna o Nascimento
   *
   * @return std::string Nascimento
   */
  Data getNascimento() const;


  /**
   * @brief Retorna o Endereco
   *
   * @return std::string Endereco
   */
  std::string getEndereco() const;


  /**
   * @brief Retorna o Matricula
   *
   * @return std::string Matricula
   */
  int getMatricula() const;


  /**
   * @brief Retorna o Registro de Salários
   *
   * @return std::string Registro de Salários
   */
  list<double> getRegistroSalario() const;

  /**
   * @brief Retorna o ultimo salario do registro, o atual.
   *
   * @return std::double salário atual
   */
  double getSalarioatual() const;

  /**
   * @brief Atualiza o nascimento
   *
   * @param Novo nascimento
   */
  void setNascimento(const Data nascimento);

  /**
   * @brief Atualiza o endereço
   *
   * @param Novo endereço
   */
  void setEndereco(const std::string& endereco);

  /**
   * @brief Atualiza a matricula
   *
   * @param Nova matrícula
   */
  void setMatricula(const int matricula);

  /**
   * @brief Adiciona lista de salários, substituindo a anterior
   *
   * @param Nova lista de salários
   */
  void setRegistroSalario(const list<double> registro_salario);

  /**
   * @brief Adiciona novo salário
   *
   * @param Novo salário
   */
  void addSalario(const double salario);

};

#endif