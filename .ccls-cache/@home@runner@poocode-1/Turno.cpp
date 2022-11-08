#include "Turno.hpp"

Turno::Turno(std::string periodo, int hora_entrada, int minuto_entrada, int hora_saida, int minuto_saida) {
  _Periodo = periodo;
  setHorarioEntrada(hora_entrada, minuto_entrada);
  setHorarioSaida(hora_saida, minuto_saida);
}

std::string Turno::getPeriodo(){
  return _Periodo;
}

void Turno::setHorarioEntrada(int hora, int minuto) {
  _HorarioEntrada.setHora(hora);
  _HorarioEntrada.setMin(minuto);
}

Data Turno::getHorarioEntrada(){
  return _HorarioEntrada;
}

void Turno::setHorarioSaida(int hora, int minuto) {
  _HorarioSaida.setHora(hora);
  _HorarioSaida.setMin(minuto);
}

Data Turno::getHorarioSaida(){
  return _HorarioSaida;
}
