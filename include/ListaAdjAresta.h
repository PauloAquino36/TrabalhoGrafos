#ifndef LISTA_ADJ_ARESTA_H
#define LISTA_ADJ_ARESTA_H

#include "NoAresta.h"

class ListaAdjAresta {
private:
    NoAresta* cabeca;           // Ponteiro para o primeiro nó da lista

public:
    // Construtor e Destrutor
    ListaAdjAresta();
    ~ListaAdjAresta();

    NoAresta* getCabeca();                                          // Retorna a cabeça da lista de adjacência de arestas
    int getNumVerticesVizinhos();                                   // Retorna a quantidade de vertices vizinhos (vertices que estão na lista de arestas)
    void adicionar_aresta(int origem, int destino, int peso);       // Adiciona uma aresta à lista
    void remover_aresta(int origem, int destino);                   // Remove uma aresta da lista
};

#endif // LISTA_ADJ_ARESTA_H