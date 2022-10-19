#include "Log_List.hpp"
#include "Log.hpp"
#include "LogLeitura.hpp"

void make_log()
{
    LogLeitura a("Parâmetros");
    Log_List::getInstance().addLog(&a);
}