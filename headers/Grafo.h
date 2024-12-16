#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>

class Grafo {
private:
    int numVertices;                               // Número de vértices no grafo
    bool direcionado;                              // Flag para indicar se o grafo é direcionado ou não
public:
     bool eh_bipartido();
     int n_conexo();
     int get_grau();
     int get_ordem();
     bool eh_direcionado();
     bool vertice_ponderado();
     bool aresta_ponderada();
     bool eh_completo();
     bool eh_arvore();
     bool possui_articulacao();
     bool possui_ponte();

     Grafo();
     ~Grafo();

     //Funções auxiliares
     int get_numVertices();
     bool get_direcionado();
};

#endif
