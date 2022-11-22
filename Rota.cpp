#include "Rota.hpp"
#include <iterator>
#include <cmath>

Rota::Rota(std::pair<float,float> coordenadas_empresa, std::list<Funcionario*> _funcionarios){

    this->_funcionarios = _funcionarios;
    this->_coordenadas_empresa = coordenadas_empresa;
    this->_distancia_total = CalculaDistancia(_funcionarios, coordenadas_empresa);
    this->_tempo_total = CalculaTempo(_distancia_total, 18);
   
 }


float Rota::CalculaDistancia(std::list<Funcionario*> funcionarios, std::pair<float,float> coordenadas_empresa){

  float distancia_total = 0;
  
  std::list<Funcionario*>::iterator it;
  
  for (it = funcionarios.begin(); it != funcionarios.end(); ++it){

    if(it == funcionarios.end()){
  distancia_total += 110.57 * sqrt( pow(coordenadas_empresa.first -   
  (*funcionarios.end())->getCoordenadas().first,2) + pow(coordenadas_empresa.second-    (*funcionarios.end())->getCoordenadas().second, 2) );
      
    } 
    else{
       auto nx = std::next(it, 1);
    distancia_total += 110.57 * sqrt( pow((*nx)->getCoordenadas().first - (*it)->getCoordenadas().first,2) + pow((*nx)->getCoordenadas().second - (*it)->getCoordenadas().second, 2)) ; //calcula a distancia entre os funcionarios
    }
}

return distancia_total;
}


Data Rota::CalculaTempo(float distancia_total, float velocidade_media){
  int tempo_hora;
  float tempo_minuto;
  float aux;
  Data tempo_total;

  aux = distancia_total/velocidade_media;

  tempo_hora = (int)aux;
  tempo_minuto = aux - tempo_hora;

  tempo_minuto = tempo_minuto * 60;


  
  tempo_total.setHora(tempo_hora);
  tempo_total.setMin(tempo_minuto);

  return tempo_total;
}