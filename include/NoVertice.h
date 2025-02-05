#ifndef NO_VERTICE_H
#define NO_VERTICE_H

#include "ListaAdjAresta.h"
#include "NoAresta.h"

class NoVertice {
private:
    int idVertice;      // Identificador do vértice
    int peso;           // Peso do vértice
    int numArestas;     // Número de arestas
    NoVertice* proximo; // Ponteiro para o próximo nó vertice
    ListaAdjAresta* arestas; // Lista de adjacência de arestas

public:
    // Construtor e Destrutor
    NoVertice(int vertice, int peso);
    ~NoVertice();

    //Getters e Setters
    int getIdVertice();                                     // Retorna o identificador do vértice
    int getPesoVertice();                                   // Retorna o peso do vértice
    NoVertice* getProximo();                                // Retorna o próximo nó vertice

    void setProximo(NoVertice* proximo);                    // Define o próximo nó vertice

    ListaAdjAresta* getArestas();                           // Retorna a lista de adjacência de arestas
    int getNumArestas();                                    // Retorna o número de arestas totais
    int getNumVizinhos();                                   // Retorna o número de vizinhos do vértice (número de arestas de saida/ grau do vertice)
    void adicionar_aresta(int id, int peso);                 // Adiciona uma aresta ao vertice

};

#endif // NO_H