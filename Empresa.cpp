#include "Empresa.hpp"

#include <iostream>
#include <list>
#include <string>

// Métodos privados
Empresa::Empresa(std::pair<float,float> coordenadas){
  coordenadas_.first = coordenadas.first;
  coordenadas_.second = coordenadas.second;
}

Empresa* Empresa::_instance = nullptr;

Empresa* Empresa::getInstance(){
    if(_instance == nullptr)
    {
        _instance = new Empresa(make_pair(0, 0));
    }
    return _instance;
}

std::list<Funcionario>* Empresa::getFuncionarios(){return &_funcionarios;}

std::list<Cargo>* Empresa::getCargos(){return &_cargos;}

std::list<Departamento>* Empresa::getDepartamentos(){return &_departamentos;}

std::list<Produto>* Empresa::getProdutos(){return &_produtos;}

std::list<Cliente>* Empresa::getClientes(){return &_clientes;}

std::list<Lote>* Empresa::getLotes(){return &_lotes;}

std::list<Venda>* Empresa::getVendas(){return &_vendas;}

std::list<Grupos>* Empresa::getGrupos(){return &_grupos_de_permissoes;}

std::list<MateriaPrima>* Empresa::getMP(){return &materiaprima_;}

std::list<Fornecedor>* Empresa::getFornecedores(){return &_fornecedores;}