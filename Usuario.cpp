#include "Usuario.hpp"


Usuario::Usuario(){};

Usuario* Usuario::_instance = nullptr;

Usuario* Usuario::getInstance(std::list<std::string> Grupos)
{
    if(_instance == nullptr)
    {
        _instance = new Usuario();
    }

    _instance->limpaPermissao(); // Garante que cada nova intância não herda permissões de outros usuários
    _instance->carregaPermissao(Grupos);
    
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

}