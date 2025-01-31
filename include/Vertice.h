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
    void setArestas(Aresta* arestas);

    Aresta* getArestas();
    int getGrauVertice();
    bool existeAresta(int destino);
    void adicionarAresta(int destino, int peso = 1);
};

#endif
