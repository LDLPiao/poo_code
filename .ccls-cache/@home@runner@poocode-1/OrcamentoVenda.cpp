#include "OrcamentoVenda.hpp"

OrcamentoVenda::OrcamentoVenda(std::map<Produto*, int> carrinho,Cliente* cliente, std::string forma_de_pagamento){
  _carrinho = carrinho;
  _cliente = cliente;
  _valor_total = ValorTotal();
  _forma.set2(forma_de_pagamento);
}

Cliente* OrcamentoVenda::getCliente() const{
  return _cliente;
}

double OrcamentoVenda::ValorTotal(){
  double tot = 0;
  for (auto it = _carrinho.begin(); it != _carrinho.end(); it++)
  {
      tot += (it->first->getDinheiro().getValor() * it->second); 
  }
  return tot;
}

double OrcamentoVenda::getValorTotal(){

return _valor_total;  
}

void OrcamentoVenda::addProduto(Produto &produto, int quantidade){

  _carrinho.insert({&produto,quantidade});
  
}
void OrcamentoVenda::addPedido(Data data, std::list<Pagamento> pagamento){

  //OrcamentoVenda x(data, carrinho, cliente);

  PedidoVenda a(pagamento, data);

  _lista_pedidos.push_back(a);
  
}

void OrcamentoVenda::Comprar(bool ciente)
{
  if(_valor_total != ValorTotal() && !ciente)throw  ExcecaoPadrao ("Compra não autorizada, valor atual não condiz com o valor do orcamento");
  _valor_total =  ValorTotal();
  Pagamento pa(_forma , 0, Data::dateNow(), _valor_total);
  std::list<Pagamento> pg {pa}; 
  PedidoVenda pe(pg, Data::dateNow());
  _lista_pedidos.push_back(pe);
  for (auto it = _carrinho.begin(); it != _carrinho.end(); it++)
  {
      it->first->Vender(it->second);
  }
}
