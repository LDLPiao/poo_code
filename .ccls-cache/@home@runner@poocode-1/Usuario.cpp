#include "Usuario.hpp"


Usuario::Usuario(){};

Usuario* Usuario::_instance = nullptr;

Usuario* Usuario::Login(std::list<std::string> Grupos)
{
    if(_instance == nullptr)
    {
        _instance = new Usuario();
    }
    _instance->carregaPermissao(Grupos);

    return _instance;
}

Usuario* Usuario::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new Usuario();
    }
    return _instance;
}

bool Usuario::checkPermissao(std::string permissao)
{
    std::set<std::string>::iterator it;
    it = this->_permissoes.find(permissao);
    if (it != _permissoes.end()) return true;
    return false;
}

void Usuario::carregaPermissao(std::list<std::string>)
{
    std::list<Grupos> grupos_de_permissoes;
    grupos_de_permissoes = *Empresa.getGrupos(); // Eu preciso da intância de empresa!!!
}