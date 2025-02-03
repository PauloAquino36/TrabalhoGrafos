#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H

#include "Grafo.h"

class GrafoMatriz  : public Grafo {
protected:
    int** matrizAdj;  // Matriz de adjacência

public:
    // Contrutor e Destrutor
    GrafoMatriz(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);
    ~GrafoMatriz();

    // Funções auxiliares
    int grauVertice(int vertice);
    //Vertice& getVertice(int vertice);                                   //Retorna um vertice especifico do grafo
    void adicionar_aresta(int origem, int destino, int peso = 1) override;        //Adiciona uma aresta no grafo
    
    // Funcoes de imprimir
    void imprimirMatrizAdj();                                           //Imprime a matriz de adjacência
    void imprimeGrafoMatriz();                                          //Imprime os atributos do grafo
};

#endif // GRAFOMATRIZ_H