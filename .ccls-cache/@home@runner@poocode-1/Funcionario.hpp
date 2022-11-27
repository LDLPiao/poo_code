#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Pessoa.hpp"
#include "Data.h"
#include "Admissao.hpp"
#include "Cargo.hpp"
#include "Dinheiro.hpp"
#include "Departamento.hpp"
#include "Endereco.hpp"

class Veiculo;

#include <string>
#include <list>
#include <map>

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
  Endereco _endereco;

  /**
   * @brief Número de matrícula do funcionário
   */
  int _matricula;

  /**
   * @brief Registros com o histórico de salários do funcionário,
   * o primeiro da lista é o mais recente e atual.
   */
  list<Dinheiro> _registro_salario;

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

  /**
   * @brief 
   * 
   */
  //std::pair<float,float> coordenadas_;

  /**
   * @brief 
   * 
   */
  Data horario_;

  /**
   * @brief 
   * 
   */
  Veiculo* _transporte;

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
  Funcionario(const std::string nome, const std::string email, const string cpf, const Data nascimento, Endereco endereco, const int matricula);

  /**
   * @brief Retorna a data de nascimento do funcionário
   */
  Data getNascimento() const;


  /**
   * @brief Retorna o endereço do funcionário
   */
   Endereco getEndereco() const;


  /**
   * @brief Retorna a matrícula do funcionário
   */
  int getMatricula() const;


  /**
   * @brief Retorna o registro de salários do funcionário
   */
  list<Dinheiro> getRegistroDinheiro() const;

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
  double getDinheiroatual() const;

  /**
   * @brief Retorna o cargo do funcionário
   */
  Cargo* getCargo() const;

  /**
   * @brief Retorna o departamento do funcionário
   */
  Departamento* getDepartamento() const;

  /**
   * @brief Retorna as coordenadas do funcionário
   */
  // std::pair<float,float> getCoordenadas() const;

  /**
   * @brief Retorna o horario de embarque do funcionário
   */
  Data getHorario() const;


  /**
   * @brief Atualiza o nascimento do funcionário
   * @param Novo nascimento
   */
  void setNascimento(const Data nascimento);

  /**
   * @brief Atualiza o endereço do funcionário
   * @param Novo endereço
   */
  void setEndereco(Endereco endereco);

  /**
   * @brief Atualiza a matricula do funcionário
   * @param Nova matrícula
   */
  void setMatricula(const int matricula);

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
   * @brief Atualiza o horario de embarque do funcionario
   * @param Novo horario
   */
  void setHorario(Data horario);

  /**
   * @brief Atualiza a coordenada do funcionario
   */
  // void setCoordenadas (std::pair<float,float> coordenadas);

  /**
   * @brief Promove o funcionário
   * @param salario novo salario do funcionário
   * @param cargo novo cargo do funcionário
   * @param departamento novo do funcionário
   */
  void Promover(const double salario, Cargo &cargo, Departamento &departamento);

  void setVeiculo(Veiculo* v){_transporte = v;}
  Veiculo* getVeiculo(){return _transporte;}

};

#endif