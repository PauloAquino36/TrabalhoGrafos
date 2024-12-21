#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "Vertice.h"

class Grafo {
protected:
    Vertice* vertices; // Lista de vértices
    int nVertices;   // Número de vértices
    bool direcionado;  // Indica se o grafo é direcionado
    bool ponderadoVertices;
    bool ponderadoArestas;

public:
     bool eh_bipartido();                   //  Lucas
     int n_conexo();                        //  Lucas
     int get_grau();                        //  Leandro
     int get_ordem();                       //  Leandro
     bool eh_direcionado();                 //  Paulo
     bool vertice_ponderado();              //  Paulo
     bool aresta_ponderada();               //  Paulo
     bool eh_completo();                    //  Leticia
     bool eh_arvore();                      //  Leticia
     bool possui_articulacao();             //  Favio
     bool possui_ponte();                   //  Favio

     Grafo(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);
     ~Grafo();

     //funçoes auxiliares
     Vertice* getVertices();
};

#endif
