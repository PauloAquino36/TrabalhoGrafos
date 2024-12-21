#ifndef VERTICE_H
#define VERTICE_H

#include "Aresta.h"

class Vertice {
private:
    int id;
    int peso;
    Aresta* arestas; // Array dinamico de arestas
    int nArestas;

public:
    Vertice();
    Vertice(int id, int peso = 0);
    ~Vertice();

    int getId();
    void setId(int id);

    int getPeso();
    void setPeso(int peso);

    Aresta* getArestas();
    int getNArestas();
    bool existeAresta(int destino);
};

#endif
