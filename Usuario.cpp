#include "Usuario.hpp"


void Usuario::Login(Cadastro* infos)
{
    Usuario::getInstance().limpaPermissao();
    Usuario::getInstance().carregaPermissao(infos->getGrupos());
}

bool Usuario::checkPermissao(std::string permissao)
{
    std::set<std::string>::iterator it;
    it = this->_permissoes.find(permissao);
    if (it != _permissoes.end()) return true;
    return false;
}

void Usuario::carregaPermissao(std::list<Grupos*> grupos)
{
    std::list<std::string> aux;
    for(auto it1 = grupos.begin(); it1 != grupos.end(); it1++)
    {
      aux = (*it1)->getPermissoes();
      
      for(auto it2 = aux.begin(); it2 != aux.end(); it2++)
      {
        _permissoes.insert(*it2);
      }
    }
}