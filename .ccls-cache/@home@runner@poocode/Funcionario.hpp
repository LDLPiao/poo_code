#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Pessoa.hpp"
#include "Data.h"
#include "Admissao.hpp"
#include "Departamento.hpp"
#include "Cargo.hpp"

#include <string>
#include <list>

/**
 * @brief Classe que armazena e gerencia as informacoes do funcionário.
 *
 */
class Funcionario: public Pessoa {

 private:
  /**
   * @brief Data de nascimento do funcionário
   */
  Data _nascimento;

  /**
   * @brief Endereço do funcionário
   */
  string _endereco;

  /**
   * @brief Número de matrícula do funcionário
   */
  int _matricula;

  /**
   * @brief Registros com o histórico de salários do funcionário,
   * o primeiro da lista é o mais recente e atual.
   */
  list<double> _registro_salario;

  /**
   * @brief Registros de admissoes do funcionario,
   * primeiro da lista é o mais recente e atual.
   */
  list<Admissao> _admissoes;

  /**
   * @brief Registros de demissoes do funcionario,
   * primeiro da lista é o mais recente e atual.
   */
  list<Data> _demissoes;

  /**
   * @brief Ponteiro para o departamento do funcionario
   */
  Departamento* _departamento;

  /**
   * @brief Ponteiro para o cargo do funcionario
   */
  Cargo* _cargo;

 public:
  /**
   * @brief Construtor padrao que inicializa todas as variaveis privadas da
   * classe.
   *
   * @param nome nome do funcionário
   * @param email email do funcionário
   * @param cpf cpf do funcionário
   * @param nascimento data de nascimento do funcionário
   * @param endereco endereço de moradia do funcionário
   * @param matricula número de matrícula do funcionário
   */
  Funcionario(const std::string nome, const std::string email, const int cpf, const Data nascimento, const std::string endereco, const int matricula);

  /**
   * @brief Retorna a data de nascimento do funcionário
   */
  Data getNascimento() const;


  /**
   * @brief Retorna o endereço do funcionário
   */
  std::string getEndereco() const;


  /**
   * @brief Retorna a matrícula do funcionário
   */
  int getMatricula() const;


  /**
   * @brief Retorna o registro de salários do funcionário
   */
  list<double> getRegistroSalario() const;

  /**
   * @brief Retorna as admissões do funcionário
   */
  list<Admissao> getAdmissoes() const;

  /**
   * @brief Retorna as demissões do funcionário
   */
  list<Data> getDemissoes() const;

  /**
   * @brief Retorna o ultimo salario do registro, o atual,  do 
   * funcionário
   */
  double getSalarioatual() const;

  /**
   * @brief Retorna o cargo do funcionário
   */
  Cargo* getCargo() const;

  /**
   * @brief Retorna o departamento do funcionário
   */
  Departamento* getDepartamento() const;

  /**
   * @brief Atualiza o nascimento do funcionário
   * @param Novo nascimento
   */
  void setNascimento(const Data nascimento);

  /**
   * @brief Atualiza o endereço do funcionário
   * @param Novo endereço
   */
  void setEndereco(const std::string endereco);

  /**
   * @brief Atualiza a matricula do funcionário
   * @param Nova matrícula
   */
  void setMatricula(const int matricula);

  /**
   * @brief Adiciona lista de salários, substituindo a anterior
   * @param Nova lista de salários
   */
  void setRegistroSalario(const list<double> registro_salario);

  /**
   * @brief Atualiza o cargo do funcionário
   * @param Novo cargo
   */
  void setCargo(Cargo &cargo);

  /**
   * @brief Atualiza o departamento do funcionário
   * @param Novo departamento
   */
  void setDepartamento(Departamento &departamento);


  /**
   * @brief Adiciona novo salário do funcionário
   * @param Novo salário
   */
  void addSalario(const double salario);

  /**
   * @brief Admite o funcionário
   */
  void Admitir(const double salario, Cargo &cargo, Departamento &departamento);

  /**
   * @brief Demite o funcionário
   */
  void Demitir();

  /**
   * @brief Promove o funcionário
   * @param salario novo salario do funcionário
   * @param cargo novo cargo do funcionário
   * @param departamento novo do funcionário
   */
  void Promover(const double salario, Cargo &cargo, Departamento &departamento);

};

#endif