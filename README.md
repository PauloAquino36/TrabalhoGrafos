# Trabalho - Teoria dos Grafos

Este projeto implementa um sistema de manipulação de grafos utilizando duas representações: lista de adjacência e matriz de adjacência. O projeto inclui classes para representar grafos, vértices e arestas, além de funções para carregar grafos a partir de arquivos, adicionar e remover vértices e arestas, e imprimir as representações dos grafos.

## Estrutura do Projeto

```
.vscode/
	settings.json
	tasks.json
docs/
	apresentacao_parte1.pdf
	contribuidores_parte1.pdf
	contribuidores_parte2.pdf
	descricao_parte1.pdf
	descricao_parte2.pdf
entradas/
	descricao.txt
	grafo.txt
include/
	Grafo.h
	GrafoLista.h
	GrafoMatriz.h
	ListaAdjAresta.h
	ListaAdjVertice.h
	NoAresta.h
	NoVertice.h
main.cpp
main.exe
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

- main.cpp: Arquivo principal que contém a função `main` para execução do programa.
- include: Diretório contendo os arquivos de cabeçalho das classes.
- src: Diretório contendo as implementações das classes.
- entradas: Diretório contendo arquivos de entrada para carregar grafos.

## Classes

### Grafo

Classe base para representar um grafo. Contém atributos e métodos comuns a todas as representações de grafos.

### GrafoLista

Classe derivada de `Grafo` que implementa a representação de grafos utilizando listas de adjacência.

### GrafoMatriz

Classe derivada de `Grafo` que implementa a representação de grafos utilizando matrizes de adjacência.

### ListaAdjVertice

Classe para representar uma lista de vértices adjacentes.

### ListaAdjAresta

Classe para representar uma lista de arestas adjacentes.

### NoVertice

Classe para representar um vértice em uma lista de adjacência.

### NoAresta

Classe para representar uma aresta em uma lista de adjacência.

## Compilação e Execução

### Compilação

Para compilar o projeto, você pode usar o comando de compilação configurado no Visual Studio Code:

1. Pressione `CTRL+SHIFT+B` para compilar o projeto.

Ou use o comando `g++` no terminal:

```
g++ -o main main.cpp src/Grafo.cpp src/GrafoMatriz.cpp src/GrafoLista.cpp src/ListaAdjAresta.cpp src/ListaAdjVertice.cpp src/NoAresta.cpp src/NoVertice.cpp
```

### Execução

Para executar o programa, use o comando:

```
./main
```

### Considerações

- O programa carrega um grafo a partir do arquivo grafo.txt.
- O grafo pode ser representado tanto por lista de adjacência quanto por matriz de adjacência.
- O código contém exemplos comentados de como adicionar e remover vértices e arestas, além de imprimir as representações dos grafos.

## Exemplo de Uso

O arquivo main.cpp contém exemplos de uso das classes `GrafoLista` e `GrafoMatriz`. Para testar a representação por lista de adjacência, descomente as linhas correspondentes no main.cpp.

```
// Exemplo de uso com GrafoLista
GrafoLista grafoLista(0, false, false, false);
grafoLista.carrega_grafo(&grafoLista, "entradas/grafo.txt");
grafoLista.imprimeGrafoLista();
grafoLista.imprimeListaAdj();
```

Para testar a representação por matriz de adjacência, use o código já presente no main.cpp.

```
// Exemplo de uso com GrafoMatriz
GrafoMatriz grafoMatriz(0, false, false, false);
grafoMatriz.carrega_grafo(&grafoMatriz, "entradas/grafo.txt");
grafoMatriz.imprimeGrafoMatriz();
grafoMatriz.imprimirMatrizAdj();
```
