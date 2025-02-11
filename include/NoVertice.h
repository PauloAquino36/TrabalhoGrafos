#ifndef NO_VERTICE_H
#define NO_VERTICE_H

#include "ListaAdjAresta.h"
#include "NoAresta.h"

class NoVertice {
private:
    int idVertice;              // Identificador do vertice
    int peso;                   // Peso do vertice
    int numArestas;             // Numero de arestas do vertice (quantidade de vertices vizinhos)
    NoVertice* proximo;         // Ponteiro para o proximo no vertice
    ListaAdjAresta* arestas;    // Lista encadeada de arestas

public:
    // Construtor e Destrutor
    NoVertice(int vertice, int peso);
    ~NoVertice();

    // Getters e Setters
    int getIdVertice();                                     // Retorna o identificador do vertice
    int getPesoVertice();                                   // Retorna o peso do vertice
    int getNumArestas();                                    // Retorna a quantidade de arestas do vertice
    NoVertice* getProximo();                                // Retorna o proximo no vertice
    ListaAdjAresta* getArestas();                           // Retorna a lista encadeada de arestas
    
    void setProximo(NoVertice* proximo);                    // Define o proximo no vertice
    int setIdVertice(int novoId);                                     // Define o identificador do vertice
    
    // Funcoes auxiliares
    int getNumVizinhos();                                   // Retorna o numero de vizinhos do vertice (numero de arestas de saida/ grau do vertice)
    void adicionar_aresta(int id, int peso);                // Adiciona uma aresta ao vertice
    void remover_aresta(int destino);                       // Remove uma aresta do vertice
    void remover_primeira_aresta();                         // Remove a primeira aresta do vertice
};

#endif // NO_H