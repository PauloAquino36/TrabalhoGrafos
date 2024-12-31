#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "Vertice.h"

class Grafo {
protected:
    Vertice* vertices; // Lista de vértices
    int nVertices;   // Número de vértices
    int grau;        // Grau do grafo
    bool direcionado;  // Indica se o grafo é direcionado
    bool ponderadoVertices;
    bool ponderadoArestas;

public:
    bool eh_bipartido();                   //  Lucas
    int n_conexo();                        //  Lucas
    int get_grau();                        //  Leandro // Ja esta Feita :)
    int get_ordem();                       //  Leandro // Ja esta Feita :)
    bool eh_direcionado();                 //  Paulo // Ja esta Feita :)
    bool vertice_ponderado();              //  Paulo // Ja esta Feita :)
    bool aresta_ponderada();               //  Paulo // Ja esta Feita :)
    bool eh_completo();                    //  Leticia
    bool eh_arvore();                      //  Leticia
    bool possui_articulacao();             //  Favio
    bool possui_ponte();                   //  Favio
    static Grafo* gera_grafo(const std::string& nomeArquivo); //  Lucas

    Grafo(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas, int grau);
    ~Grafo();

    //funçoes auxiliares
    Vertice* getVertices();
    void adicionarAresta(int origem, int destino, int peso);
};

#endif
