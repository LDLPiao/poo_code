#include <iostream>
#include <string.h>
#include "Usuario.hpp"


Usuario::Usuario(){};

Usuario* Usuario::_instance = nullptr;

Usuario* Usuario::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new Usuario();
    }
    return _instance;
}

bool Usuario::checkPermissao(std::string)
{

}

