#ifndef LISTA_ADJ_ARESTA_H
#define LISTA_ADJ_ARESTA_H

#include "NoAresta.h"

class ListaAdjAresta {
private:
    NoAresta* cabeca;           // Ponteiro para o primeiro no da lista

public:
    // Construtor e Destrutor
    ListaAdjAresta();
    ~ListaAdjAresta();

    NoAresta* getCabeca();                                          // Retorna a cabeca da lista de adjacencia de arestas
    int getNumVerticesVizinhos();                                   // Retorna a quantidade de vertices vizinhos (vertices que estao na lista de arestas)
    void adicionar_aresta(int origem, int destino, int peso);       // Adiciona uma aresta à lista
    void remover_aresta(int origem, int destino);                   // Remove uma aresta da lista
    void remover_primeira_aresta();                                 // Remove a primeira aresta da lista
};

#endif // LISTA_ADJ_ARESTA_H