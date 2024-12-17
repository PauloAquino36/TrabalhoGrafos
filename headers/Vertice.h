#ifndef VERTICE_H
#define VERTICE_H

#include "Aresta.h"

class Vertice {
private:
    int id;          
    int peso;        
    Aresta* arestas; // Lista dinâmica de arestas
    int numArestas;  
    int capacidade;  // Capacidade máxima da lista de arestas
    void redimensionarArestas(); // Função auxiliar para redimensionar a lista de arestas

public:
    Vertice();                   // Construtor padrão
    Vertice(int id, int peso = 0);   // Construtor com ID e peso (peso padrão = 0)
    ~Vertice();                  // Destrutor

    int getId();
    void setId(int id);

    int getPeso();
    void setPeso(int peso);

    void adicionarAresta(int destino, int peso = 0);
    void removerAresta(int destino);
    bool existeAresta(int destino);
    int getPesoAresta(int destino);

    void imprimirArestas();
};

#endif
