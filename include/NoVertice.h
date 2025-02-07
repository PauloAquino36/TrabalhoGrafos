#ifndef NO_VERTICE_H
#define NO_VERTICE_H

#include "ListaAdjAresta.h"
#include "NoAresta.h"

class NoVertice {
private:
    int idVertice;              // Identificador do vértice
    int peso;                   // Peso do vértice
    int numArestas;             // Número de arestas do vertice (quantidade de vertices vizinhos)
    NoVertice* proximo;         // Ponteiro para o próximo nó vertice
    ListaAdjAresta* arestas;    // Lista encadeada de arestas

public:
    // Construtor e Destrutor
    NoVertice(int vertice, int peso);
    ~NoVertice();

    // Getters e Setters
    int getIdVertice();                                     // Retorna o identificador do vértice
    int getPesoVertice();                                   // Retorna o peso do vértice
    int getNumArestas();                                    // Retorna a quantidade de arestas do vertice
    NoVertice* getProximo();                                // Retorna o próximo nó vertice
    ListaAdjAresta* getArestas();                           // Retorna a lista encadeada de arestas
    
    void setProximo(NoVertice* proximo);                    // Define o próximo nó vertice
    
    // Funcoes auxiliares
    int getNumVizinhos();                                   // Retorna o número de vizinhos do vértice (número de arestas de saida/ grau do vertice)
    void adicionar_aresta(int id, int peso);                // Adiciona uma aresta ao vertice
    void remover_aresta(int destino);                       // Remove uma aresta do vertice
};

#endif // NO_H