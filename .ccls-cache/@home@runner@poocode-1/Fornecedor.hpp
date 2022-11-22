#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include "Pessoa.hpp"
#include "MateriaPrima.hpp"
#include <string>
#include <map>


/**
 * @brief Classe que armazena e gerencia as informacoes do funcionário.
 *
 */
class Fornecedor: public Pessoa {

 private:
  
  /**
   * @brief Lista de materias primas disponiveis com o preço atrelado
   */
    std::map<MateriaPrima*, double> _precos;
 

 public:
  /**
   * @brief Construtor padrao que inicializa todas as variaveis privadas da
   * classe.
   *
   * @param nome nome do fornecedor
   * @param email email do fornecedor
   * @param cnpj  cnpj do fornecedor
   * @param precos map de materia primas e precos do fornecedor 
   */
  Fornecedor(const std::string nome, const std::string email, const std::string cnpj, std::map<MateriaPrima*, double> precos);

  /**
   * @brief Adiciona uma nova materia prima a lista
   */
  void addMateriaPrima(MateriaPrima* materia_prima, double preco ) ;


  /**
   * @brief Altera o preco de uma determinada materia prima na lista
   */
  void mudarPreco(MateriaPrima* materia_prima, double preco);


  /**
   * @brief Retorna o preco de uma determinada materia prima na lista
   */
  double getPreco(MateriaPrima* materia_prima);


  /**
   * @brief Verifica se a materia prima esta na lista
   */
  bool checkMateriaPrima(MateriaPrima* materia_prima);

   
};
#endif