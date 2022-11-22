#ifndef VEICULO_H
#define VEICULO_H

#include "Funcionario.hpp"
#include "Rota.hpp"
#include <string>
#include <list>
#include <algorithm>

class Veiculo
{
  private:

    std::string placa;
    int capacidade;
    std::list<Funcionario*> funcionarios;
    static float velocidade;
    Rota* rota = nullptr;

  public:

    Veiculo(std::string _placa, int _capacidade);

    std::string getPlaca();
    int getCapacidade();
    float getVelocidade();
    Rota* getRota();

    void setRota(Rota* _rota);

    /**
    *@brief Checa se existe vaga para mais funcionários no veículo
    */
    bool checkCapacidade(int qtd);

    /**
    *@brief Cadastra um usuário na lista de funcionários do veículo
    */
    void addFuncionario(Funcionario* funcionario);
    
    /**
    *@brief Remove um funcionário da lista de cadastrados
    */
    void removeFuncionario(Funcionario* funcionario);
    
    /**
    *@brief Calcula os horários de embarque de cada funcionário na 
    * rota do veículo
    */
    void setHorariosEmbarque();
    
};



#endif