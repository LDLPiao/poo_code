#include "Salario.hpp"


  Salario::Salario(double salario,Data data){
    setValor(salario);
    setData(data);
  
  }

  void Salario::setData(Data data){
    _data = data;
  }
  Data Salario::getData(){
    return _data;
  }
  void Salario::setValor(double valor){
    _valor = valor;
  }
  double Salario::getValor(){
    return _valor;
  }