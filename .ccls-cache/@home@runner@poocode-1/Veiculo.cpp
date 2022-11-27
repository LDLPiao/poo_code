#include "Veiculo.hpp"


float Veiculo::velocidade = 18;

Veiculo::Veiculo(std::string _placa, int _capacidade) {
  this->placa = _placa;
  this->capacidade = _capacidade;
}

std::string Veiculo::getPlaca() { return placa; }

int Veiculo::getCapacidade() { return capacidade; }

float Veiculo::getVelocidade() { return velocidade; }

Rota* Veiculo::getRota() { return rota; }

void Veiculo::setRota(Rota* _rota) { this->rota = _rota; }

bool Veiculo::checkCapacidade(int qtd) {
  // Recupera o tamanho da lista funcionarios
  int _size = funcionarios.size();

  if (_size + qtd > capacidade) {
    return false;
  }
  return true;
}

void Veiculo::addFuncionario(Funcionario *funcionario) {
  if (checkCapacidade(1)) {
    funcionarios.push_back(funcionario);
  }
  // TODO: Jogar excessão quando não houver vagas para o funcionário
}

void Veiculo::removeFuncionario(Funcionario *funcionario) {
  list<Funcionario *>::iterator it;
  it = std::find(funcionarios.begin(), funcionarios.end(), funcionario);
  if (it != funcionarios.end()) {
    funcionarios.erase(it);
  }
  // TODO: jogar excessão caso não seja encontrado o funcionário na lista
}

void Veiculo::setHorariosEmbarque(){


  std::list<Funcionario*>::reverse_iterator revit;
  float tempo_de_chegada =  7.83; //7h50
  Endereco endereco_empresa = this->getRota()->getEnderecoEmpresa();

     for (revit = funcionarios.rbegin(); revit != funcionarios.rend(); ++revit){
     float distancia = 0;

      if(revit == funcionarios.rbegin()){
      distancia = (*revit)->getEndereco().distancia_ate(endereco_empresa);
        }

      else{
      auto nx = std::next(revit, -1);
      distancia = (*revit)->getEndereco().distancia_ate((*nx)->getEndereco());

      }

    float tempo_jornada = (distancia*0.001)/velocidade;//converte para km
    tempo_de_chegada -= tempo_jornada;

    Data tempo_embarque;

        int tempo_hora = (int)tempo_de_chegada;
        float tempo_minuto = tempo_de_chegada - tempo_hora;
        tempo_minuto = tempo_minuto * 60;
       
        tempo_embarque.setHora(tempo_hora);
        tempo_embarque.setMin(tempo_minuto);
        
       (*revit)->setHorario(tempo_embarque);
       
  }
}












//----------------------------------------------------------------------//
// void Veiculo::setHorariosEmbarque(){
//     std::list<Funcionario*>::reverse_iterator revit;
//   float tempo_de_chegada =  7.83; //7h50
//   std::pair<float,float> coordenadas_empresa = this->getRota()->getCoordenadasEmpresa();
  
//   for (revit = funcionarios.rbegin(); revit != funcionarios.rend(); ++revit){
//      float distancia = 0;
    
//      if(revit == funcionarios.rbegin()){
//     distancia += 110.57 * sqrt( pow(coordenadas_empresa.first - (*funcionarios.rbegin())->getCoordenadas().first,2) + pow(coordenadas_empresa.second - (*funcionarios.rbegin())->getCoordenadas().second, 2));
//      }
//     else{
//        auto nx = std::next(revit, -1);
//     distancia = 110.57 * sqrt( pow((*nx)->getCoordenadas().first - (*revit)->getCoordenadas().first,2) + pow((*nx)->getCoordenadas().second - (*revit)->getCoordenadas().second, 2)); //calcula a distancia entre os funcionarios
//     }
// //CONVERSAO
  
//   int tempo_hora;
//   float tempo_minuto;
//   float aux;
//   Data tempo_total;
//   aux = distancia/18;
//   tempo_de_chegada -= aux;
//   tempo_hora = (int)tempo_de_chegada;
//   tempo_minuto = tempo_de_chegada - tempo_hora;
//   tempo_minuto = tempo_minuto * 60;
  
//   tempo_total.setHora(tempo_hora);
//   tempo_total.setMin(tempo_minuto);
// (*revit)->setHorario(tempo_total);
    
// }

  
// }
