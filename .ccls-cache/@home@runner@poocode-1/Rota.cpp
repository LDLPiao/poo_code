#include "Rota.hpp"

Rota::Rota(float tempo_total, float distancia_total, static std::pair<float,float> coordenadas_empresa){

   
 }


float Rota::CalculaDistancia(std::list<Funcionario*> funcionarios, static std::pair<float,float> coordenadas_empresa){

  float distancia_total = 0;
  
  std::list<Funcionario*>::iterator it;
  
  for (it = funcionarios.begin(); it != (funcionarios.end() - 1); ++it){
      
    distancia_total += 110.57 * sqrt( pow((it+1).getCoordenadas().first - it.getCoordenadas().first,2) + pow((it+1).getCoordenadas().second-        it.getCoordenadas().second, 2) ); //calcula a distancia entre os funcionarios
  
}
distancia_total += 110.57 * sqrt( pow(coordenadas_empresa.first - fucionarios.end().getCoordenadas().first,2) + pow(coordenadas_empresa.second-        funcionarios.end().getCoordenadas().second, 2) ); //calcula a distancia do ultimo funcionario da lista ate a empresa e acrescenta na distancia total

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
}