#include "OrcamentoVenda.hpp"

OrcamentoVenda::OrcamentoVenda(Data data, std::map<Produto*, int> carrinho,Cliente& cliente): Orcamento(data){

  _carrinho = carrinho;
  _cliente = &cliente;
  
}

Cliente* OrcamentoVenda::getCliente() const{
  return _cliente;
}

void OrcamentoVenda::setValorTotal(){
  map<Produto*, int>::iterator it;
  _valor_total = 0;

for (it = _carrinho.begin(); it != _carrinho.end(); it++)
{
    _valor_total += (it->first->getDinheiro().getValor() * it->second); 
}
  
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
