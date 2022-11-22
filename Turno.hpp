#ifndef TURNO_H
#define TURNO_H

#include <iostream>
#include <string>
#include "Data.h"

class Turno {
  private:
  std::string _Periodo;
  Data _HorarioEntrada;
  Data _HorarioSaida;

  public:
   /**
   * @brief Construtor de Turno
   *
   */
  Turno(std::string periodo, int hora_entrada, int minuto_entrada, int hora_saida, int minuto_saida);

  /**
   * @brief Retorna o valor contido em _Periodo.
   */
  std::string getPeriodo();

  /**
   * @brief Atribui um valor à _HorarioEntrada.
   */
  void setHorarioEntrada(int hora, int minuto);
  /**
   * @brief Retorna o valor contido em _HorarioEntrada.
   */
  Data getHorarioEntrada();

  /**
   * @brief Atribui um valor à _HorarioSaida.
   */
  void setHorarioSaida(int hora, int minuto);
  /**
   * @brief Retorna o valor contido em _HorarioSaida.
   */
  Data getHorarioSaida();

};
#endif