#ifndef ARESTA_H
#define ARESTA_H

#include <iostream>

class Aresta {
private:
    int idOrigem;                   // Id do vértice de origem
    int idDestino;                  // Id do vertice de destino
    int peso;                       // Peso da aresta
    Aresta* proxima;                // Ponteiro para a próxima aresta

public:
    // Construtor e Destrutor
    Aresta(int idDestino, int peso = 0);
    ~Aresta();

    // Getters e Setters
    int getIdOrigem();
    int getIdDestino();
    int getPeso(); 
    Aresta* getProxima();

    void setPeso(int peso);
    void setProxima(Aresta* prox);
};

#endif