#include "Log.hpp"

Log::Log(Data data, std::string entidade) {
  data_ = data;
  entidade_ = entidade;
  }

void Log::setData(Data data) {
    data_ = data;
}

Data Log::getData() {
    return data_;
}

void Log::setEntidade(std::string entidade) {
    entidade_ = entidade;
}

std::string Log::getEntidade() {
  return entidade_;
}
