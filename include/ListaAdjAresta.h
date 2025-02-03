#ifndef LISTA_ADJ_ARESTA_H
#define LISTA_ADJ_ARESTA_H

#include "NoAresta.h"

class ListaAdjAresta {
private:
    NoAresta* cabeca; // Ponteiro para o primeiro nó da lista

public:
    ListaAdjAresta(); // Construtor
    ~ListaAdjAresta(); // Destrutor

    NoAresta* getCabeca(); // Retorna a cabeça da lista de adjacência de arestas
    void adicionar_aresta(int origem, int destino, int peso); // Adiciona uma aresta à lista
};

#endif // LISTA_ADJ_ARESTA_H