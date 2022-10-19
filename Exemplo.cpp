#include "Log_List.hpp"
#include "Log.hpp"
#include "LogLeitura.hpp"

void make_log()
{
    Log_List::getInstance().addLog(&LogLeitura("Parâmetros"));
}