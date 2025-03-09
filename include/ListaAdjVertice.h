#ifndef LISTA_ADJ_VERTICE_H
#define LISTA_ADJ_VERTICE_H

#include "NoVertice.h"
class GrafoLista; // Forward declaration

class ListaAdjVertice {
private:
    GrafoLista* grafo;          // Ponteiro para o grafo
    NoVertice* cabeca;          // Ponteiro para o primeiro no da lista
    GrafoLista* grafo;               // Ponteiro para o grafo

public:
    // Construtor e Destrutor
    ListaAdjVertice(GrafoLista* grafo);
    ~ListaAdjVertice();

    NoVertice* getCabeca();                                                         // Retorna a cabeca da lista de adjacencia de arestas
    int getNumVertices();                                                           // Retorna a quantidade de vertices na lista (vertices totais no grafo)
    NoVertice* getVertice(int id);                                                  // Retorna um vertice da lista
    void adicionar_vertice(int id, float peso);                                     // Adiciona um vertice à lista
    void adicionar_aresta(int origem, int destino, float peso);       // Adiciona uma aresta ao vertice
    void remover_aresta(int origem, int destino);                                   // Remove uma aresta do vertice
    void remover_primeira_aresta(int id);                                           // Remove a primeira aresta do vertice
    void remover_vertice(int id);                                                   // Remove um vertice da lista

    // Funcoes imprime
    void imprimir();                                                                // Imprime a Lista de adjacencia
};

#endif // LISTA_ADJ_VERTICE_H