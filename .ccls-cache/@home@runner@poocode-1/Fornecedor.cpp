#include "Fornecedor.hpp"

#include <iostream>

Fornecedor::Fornecedor(const std::string nome, const std::string email,
                         const std::string cnpj, std::map<MateriaPrima*, double> precos)
    : Pessoa(nome, email) {

      _precos = precos;
}
 
void Fornecedor::addMateriaPrima(MateriaPrima* materia_prima, double preco ) {

   _precos.insert({materia_prima, preco});

 }

  void Fornecedor::mudarPreco(MateriaPrima* materia_prima, double preco){
    
  std::map<MateriaPrima*, double>::iterator it;

    it = _precos.find(materia_prima);
    it->second = preco;    
}


double Fornecedor::getPreco(MateriaPrima* materia_prima) {

  std::map<MateriaPrima*, double>::iterator it;

    it = _precos.find(materia_prima);
    return it->second;
}
 bool Fornecedor::checkMateriaPrima(MateriaPrima* materia_prima){

    if (_precos.count(materia_prima) > 0)
        return true;
   else
      return false;

   
 }