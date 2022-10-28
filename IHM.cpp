#include <string>
#include <iostream>
#include "Usuario.hpp"

#define println(txt) std::cout << txt << std::endl; //macro para imprimir texto com quebra de linha.

void prompt(std::string comand)
{
    if(!Usuario::getInstance().checkPermissao(comand)); //throw

    if (comand.compare("?"))
    {
        println("|===================|Comandos|===================|");
        println("logar => Realizar login no sistema");
        println("cadastrar => Realizar um cadastro no sistema");
        println("vender => Realizar uma venda no sistema");
    }
    else if (comand.compare("logar"))
    {
        /* code */
    }
    else if (comand.compare("cadastrar"))
    {
        println("Qual tipo de cadastro deseja realizar?");
        println("1 - Funcionário");
        println("2 - Cliente");
        println("3 - Fornecedor");
        println("4 - Produto");
        println("5 - Matéria Prima");
        println("6 - Forma de Pagamento");
        println("7 - Cargo");
        println("8 - Departamento");
    }
    else if (comand.compare(""))
    {
        /* code */
    }
    
    
}