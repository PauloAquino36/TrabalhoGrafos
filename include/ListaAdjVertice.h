#ifndef LISTA_ADJ_VERTICE_H
#define LISTA_ADJ_VERTICE_H

#include "NoVertice.h"

class ListaAdjVertice {
private:
    NoVertice* cabeca;          // Ponteiro para o primeiro no da lista

public:
    // Construtor e Destrutor
    ListaAdjVertice();
    ~ListaAdjVertice();

    NoVertice* getCabeca();                                         // Retorna a cabeca da lista de adjacencia de arestas
    int getNumVertices();                                           // Retorna a quantidade de vertices na lista (vertices totais no grafo)
    NoVertice* getVertice(int id);                                  // Retorna um vertice da lista
    void adicionar_vertice(int id, int peso);                       // Adiciona um vertice à lista
    void adicionar_aresta(int origem, int destino, int peso);       // Adiciona uma aresta ao vertice
    void remover_aresta(int origem, int destino);                   // Remove uma aresta do vertice
    void remover_vertice(int id);                                   // Remove um vertice da lista

    // Funcoes de imprimir
    void imprimir();                                                // Imprime a Lista de adjacencia
};

#endif // LISTA_ADJ_VERTICE_H