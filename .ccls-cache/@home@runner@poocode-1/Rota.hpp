#ifndef ROTA_H
#define ROTA_H

#include "Data.h"
#include "Funcionario.hpp"
//#include "Empresa.hpp"

#include <iostream>
#include <string>
#include <list>

class Rota {
  private:
    // Data _tempo_total;
    // float _distancia_total;
    Endereco _endereco_empresa;
    std::list<Funcionario*> _funcionarios;

  public:
   /**
   * @brief Construtor da classe que cria uma rota
   *
   */
  Rota(Endereco endereco_empresa,std::list<Funcionario*> funcionarios);

  /**
   * @brief Funcao que retorna a lista de funcionarios na rota
   *
   */
   std::list<Funcionario*> getFuncionarios();
  
   Endereco getEnderecoEmpresa();

//--------------------------------------------------------------------------//
  // /**
  //  * @brief Calcula e retorna o valor da distancia total da rota
  //  */
  // float CalculaDistancia(std::list<Funcionario*> funcionarios, std::pair<float,float> coordenadas_empresa);
  // /**
  //  * @brief calcula e retorna o tempo total da rota
  //  */
  // Data CalculaTempo(float distancia_total, float velocidade_media);

};
#endif