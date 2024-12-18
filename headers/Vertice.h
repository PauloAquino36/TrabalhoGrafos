#ifndef VERTICE_H
#define VERTICE_H

#include "Aresta.h"

class Vertice {
private:
    int id;
    int peso;
    Aresta* arestas; // Array dinâmico de arestas
    int numArestas;
    int capacidade;

    void redimensionarArestas();

public:
    Vertice();
    Vertice(int id, int peso = 0);
    Vertice(const Vertice& other); // Construtor de cópia
    Vertice& operator=(const Vertice& other); // Operador de atribuição
    ~Vertice();

    int getId() const;
    void setId(int id);

    int getPeso() const;
    void setPeso(int peso);

    int getPesoAresta(int destino) const;

    void adicionarAresta(int destino, int peso = 0);
    void removerAresta(int destino);
    bool existeAresta(int destino) const;

    void imprimirArestas() const;
};

#endif
