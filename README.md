# Trabalho - Teoria dos Grafos

Este projeto implementa um sistema de manipulacao de grafos utilizando duas representacoes: lista de adjacencia e matriz de adjacencia. O projeto inclui classes para representar grafos, vertices e arestas, alem de funcoes para carregar grafos a partir de arquivos, adicionar e remover vertices e arestas, e imprimir as representacoes dos grafos.

## Estrutura do Projeto

```
.vscode/
	settings.json
	tasks.json
docs/
	contribuidores.pdf
	descricao.pdf
	documentacao.pdf
	relatorio.pdf
entradas/
	descricao.txt
	grafo.txt
	instancia1.txt
	instancia2.txt
	instancia3.txt
	instancia4.txt
	instancia5.txt
	instancia6.txt
	instancia7.txt
	instancia8.txt
	instancia9.txt
	instancia10.txt
include/
	Grafo.h
	GrafoLista.h
	GrafoMatriz.h
	ListaAdjAresta.h
	ListaAdjVertice.h
	NoAresta.h
	NoVertice.h
main.cpp
src/
	Grafo.cpp
	GrafoLista.cpp
	GrafoMatriz.cpp
	ListaAdjAresta.cpp
	ListaAdjVertice.cpp
	NoAresta.cpp
	NoVertice.cpp
```

## Arquivos Principais

- main.cpp: Arquivo principal que contem a funcao `main` para execucao do programa.
- include: Diretorio contendo os arquivos de cabecalho das classes.
- src: Diretorio contendo as implementacoes das classes.
- entradas: Diretorio contendo arquivos de entrada para carregar grafos.

## Classes

### Grafo

Classe base para representar um grafo. Contem atributos e metodos comuns a todas as representacoes de grafos.

### GrafoLista

Classe derivada de `Grafo` que implementa a representacao de grafos utilizando listas de adjacencia.

### GrafoMatriz

Classe derivada de `Grafo` que implementa a representacao de grafos utilizando matrizes de adjacencia.

### ListaAdjVertice

Classe para representar uma lista de vertices adjacentes.

### ListaAdjAresta

Classe para representar uma lista de arestas adjacentes.

### NoVertice

Classe para representar um vertice em uma lista de adjacencia.

### NoAresta

Classe para representar uma aresta em uma lista de adjacencia.

## Compilacao e Execucao

### Compilacao

Para compilar o projeto, voce pode usar o comando de compilacao configurado no Visual Studio Code:

1. Use o comando `g++` no terminal para compilar o projeto:

```
g++ -o main main.cpp src/*.cpp
```

### Execucao

Para executar o programa, use os comandos:

```
./main -d -m entradas/grafo.txt  # Para imprimir a descricao do Grafo Matriz
./main -d -l entradas/grafo.txt  # Para imprimir a descricao do Grafo Lista
./main -p -m entradas/grafo.txt  # Para imprimir a solucao de cobertura de vertices do Grafo Matriz
./main -p -l entradas/grafo.txt  # Para imprimir a solucao de cobertura de vertices do Grafo Lista
./main -a -m entradas/grafo.txt  # Para executar a analise de algoritmos no Grafo Matriz
./main -a -l entradas/grafo.txt  # Para executar a analise de algoritmos no Grafo Lista
```

### Consideracoes

- O programa carrega um grafo a partir do arquivo grafo.txt.
- O grafo pode ser representado tanto por lista de adjacencia quanto por matriz de adjacencia.
