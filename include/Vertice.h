#ifndef VERTICE_H
#define VERTICE_H

#include "ListaAdjAresta.h"

class Vertice {
private:
    int id;                                 // Id do Vertice
    int peso;                               // Peso do Vertice
    int numArestas = 0;                     // Número de arestas
    ListaAdjAresta* arestas;                // Lista de arestas

public:
    // Construtor e Destrutor   
    Vertice(int id, int peso = 0);
    ~Vertice();

    // Getters e Setters
    int getId();
    int getPeso();
    int getNumArestas();
    ListaAdjAresta* getArestas();

    void setId(int id);
    void setPeso(int peso);
    void setNumArestas(int numArestas);

    void adicionarVertice(int origem, int destino, int peso);
    void adicionarAresta(int origem, int destino, int peso);
};

#endif
