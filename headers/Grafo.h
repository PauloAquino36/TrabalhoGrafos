#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>

class Grafo {
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
     ~Grafo() = default;
};

#endif
