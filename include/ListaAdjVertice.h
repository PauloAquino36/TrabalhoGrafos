#ifndef LISTA_ADJ_VERTICE_H
#define LISTA_ADJ_VERTICE_H

#include "NoVertice.h"

class ListaAdjVertice {
private:
    NoVertice* cabeca;          // Ponteiro para o primeiro nó da lista

public:
    // Construtor e Destrutor
    ListaAdjVertice();
    ~ListaAdjVertice();

    NoVertice* getCabeca();                                         // Retorna a cabeça da lista de adjacência de arestas
    int getNumVertices();                                           // Retorna a quantidade de vertices na lista (vertices totais no grafo)
    NoVertice* getVertice(int id);                                  // Retorna um vertice da lista
    void adicionar_vertice(int id, int peso);                       // Adiciona um vértice à lista
    void adicionar_aresta(int origem, int destino, int peso);       // Adiciona uma aresta ao vertice

    // Funcoes de imprimir
    void imprimir();                                                // Imprime a Lista de adjacência
};

#endif // LISTA_ADJ_VERTICE_H