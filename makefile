OBJS	= Admissao.o Cargo.o Cliente.o Data.o Departamento.o Dinheiro.o Empresa.o ExcecaoAcessoNegado.o ExcecaoPadrao.o FormaDePagamento.o Formato.o Fornecedor.o Funcionario.o Grupos.o Log.o LogAcessoNegado.o LogEscrita.o LogLeitura.o LogList.o Lote.o MateriaPrima.o Orcamento.o OrcamentoCompra.o OrcamentoVenda.o Ordem.o OrdemCompra.o OrdemProducao.o Pagamento.o PedidoVenda.o Pessoa.o Produto.o Rota.o Turno.o Usuario.o Veiculo.o Venda.o main.o
SOURCE	= Admissao.cpp Cargo.cpp Cliente.cpp Data.cpp Departamento.cpp Dinheiro.cpp Empresa.cpp ExcecaoAcessoNegado.cpp ExcecaoPadrao.cpp FormaDePagamento.cpp Formato.cpp Fornecedor.cpp Funcionario.cpp Grupos.cpp Log.cpp LogAcessoNegado.cpp LogEscrita.cpp LogLeitura.cpp LogList.cpp Lote.cpp MateriaPrima.cpp Orcamento.cpp OrcamentoCompra.cpp OrcamentoVenda.cpp Ordem.cpp OrdemCompra.cpp OrdemProducao.cpp Pagamento.cpp PedidoVenda.cpp Pessoa.cpp Produto.cpp Rota.cpp Turno.cpp Usuario.cpp Veiculo.cpp Venda.cpp main.cpp
HEADER	= Admissao.hpp Cadastro.hpp Cargo.hpp Cliente.hpp Data.h Departamento.hpp Dinheiro.hpp Empresa.hpp ExcecaoAcessoNegado.hpp ExcecaoPadrao.hpp ExecaoCustomizada.h ExcecaoPadrao.hpp FormaDePagamento.hpp Formato.h Fornecedor.hpp Funcionario.hpp Grupos.hpp Log.hpp LogAcessoNegado.hpp LogEscrita.hpp LogLeitura.hpp LogList.hpp Lote.hpp MateriaPrima.hpp Orcamento.hpp OrcamentoCompra.hpp OrcamentoVenda.hpp Ordem.hpp OrdemCompra.hpp OrdemProducao.hpp Pagamento.hpp PedidoVenda.hpp Pessoa.hpp Produto.hpp Rota.hpp Turno.hpp Usuario.hpp Veiculo.hpp Venda.hpp VendaOnline.hpp
OUT	= EXE
CC	 = g++
FLAGS	 = -c
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Admissao.o: Admissao.cpp
	$(CC) $(FLAGS) Admissao.cpp 

Cargo.o: Cargo.cpp
	$(CC) $(FLAGS) Cargo.cpp 

Cliente.o: Cliente.cpp
	$(CC) $(FLAGS) Cliente.cpp 

Data.o: Data.cpp
	$(CC) $(FLAGS) Data.cpp 

Departamento.o: Departamento.cpp
	$(CC) $(FLAGS) Departamento.cpp 

Dinheiro.o: Dinheiro.cpp
	$(CC) $(FLAGS) Dinheiro.cpp 

Empresa.o: Empresa.cpp Empresa.hpp
	$(CC) $(FLAGS) Empresa.cpp 

ExcecaoAcessoNegado.o: ExcecaoAcessoNegado.cpp
	$(CC) $(FLAGS) ExcecaoAcessoNegado.cpp 

ExcecaoPadrao.o: ExcecaoPadrao.cpp ExcecaoPadrao.hpp
	$(CC) $(FLAGS) ExcecaoPadrao.cpp

FormaDePagamento.o: FormaDePagamento.cpp FormaDePagamento.hpp
	$(CC) $(FLAGS) FormaDePagamento.cpp 

Formato.o: Formato.cpp
	$(CC) $(FLAGS) Formato.cpp 

Fornecedor.o: Fornecedor.cpp
	$(CC) $(FLAGS) Fornecedor.cpp 

Funcionario.o: Funcionario.cpp
	$(CC) $(FLAGS) Funcionario.cpp 

Grupos.o: Grupos.cpp
	$(CC) $(FLAGS) Grupos.cpp 

Log.o: Log.cpp Log.hpp
	$(CC) $(FLAGS) Log.cpp 

LogAcessoNegado.o: LogAcessoNegado.cpp LogAcessoNegado.hpp
	$(CC) $(FLAGS) LogAcessoNegado.cpp 

LogEscrita.o: LogEscrita.cpp LogEscrita.hpp
	$(CC) $(FLAGS) LogEscrita.cpp 

LogLeitura.o: LogLeitura.cpp LogLeitura.hpp
	$(CC) $(FLAGS) LogLeitura.cpp 

LogList.o: LogList.cpp LogList.hpp
	$(CC) $(FLAGS) LogList.cpp 

Lote.o: Lote.cpp
	$(CC) $(FLAGS) Lote.cpp 

MateriaPrima.o: MateriaPrima.cpp
	$(CC) $(FLAGS) MateriaPrima.cpp 

Orcamento.o: Orcamento.cpp
	$(CC) $(FLAGS) Orcamento.cpp 

OrcamentoCompra.o: OrcamentoCompra.cpp
	$(CC) $(FLAGS) OrcamentoCompra.cpp 

OrcamentoVenda.o: OrcamentoVenda.cpp
	$(CC) $(FLAGS) OrcamentoVenda.cpp 

Ordem.o: Ordem.cpp
	$(CC) $(FLAGS) Ordem.cpp 

OrdemCompra.o: OrdemCompra.cpp
	$(CC) $(FLAGS) OrdemCompra.cpp 

OrdemProducao.o: OrdemProducao.cpp
	$(CC) $(FLAGS) OrdemProducao.cpp 

Pagamento.o: Pagamento.cpp Pagamento.hpp
	$(CC) $(FLAGS) Pagamento.cpp 

PedidoVenda.o: PedidoVenda.cpp PedidoVenda.hpp
	$(CC) $(FLAGS) PedidoVenda.cpp 

Pessoa.o: Pessoa.cpp Pessoa.hpp
	$(CC) $(FLAGS) Pessoa.cpp 

Produto.o: Produto.cpp Produto.hpp
	$(CC) $(FLAGS) Produto.cpp 

Rota.o: Rota.cpp
	$(CC) $(FLAGS) Rota.cpp 

Turno.o: Turno.cpp
	$(CC) $(FLAGS) Turno.cpp 

Usuario.o: Usuario.cpp Usuario.hpp
	$(CC) $(FLAGS) Usuario.cpp 

Veiculo.o: Veiculo.cpp Veiculo.hpp
	$(CC) $(FLAGS) Veiculo.cpp 

Venda.o: Venda.cpp Venda.hpp
	$(CC) $(FLAGS) Venda.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 


clean:
	rm -f $(OBJS) $(OUT)