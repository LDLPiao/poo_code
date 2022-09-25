#ifndef ADMISSAO_H
#define ADMISSAO_H

#include "Data.h"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de um cliente.
 */
class Admissao{
 private:
  /**
   * @brief Booleando que mostra se o cliente é PJ ou PF
   */
  Data _data;

  /**
   * @brief Endereco de telefone do cliente
   */
  double _salario;
 public:

  /**
   * @brief Construtor da classe.
   */

  Admissao(Data data, double salario);

  /**
   * @brief Atribui um valor à _data.
   * Não usar fora do construtor, já que
   * a data não muda.
   */
  void setData(Data data);

  /**
   * @brief Retorna o valor contido em _data.
   */
  Data getData();

  /**
   * @brief Atribui um valor à _salario_inicial.
   * Não usar fora do construtor, já que
   * o salario inicial não muda.
   */
  void setSalario(double salario);

  /**
   * @brief Retorna o valor contido em _salario_inicial.
   */
  double getSalario();

};
#endif