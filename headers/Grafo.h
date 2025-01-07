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
    bool eh_bipartido();                   //  Lucas    // Ja esta Feita :)
    int n_conexo();                        //  Lucas    // Ja esta Feita :)
    int get_grau();                        //  Leandro  // Ja esta Feita :)
    int get_ordem();                       //  Leandro  // Ja esta Feita :)
    bool eh_direcionado();                 //  Paulo    // Ja esta Feita :)
    bool vertice_ponderado();              //  Paulo    // Ja esta Feita :)
    bool aresta_ponderada();               //  Paulo    // Ja esta Feita :)
    bool eh_completo();                    //  Leticia  // Ja esta Feita :)
    bool eh_arvore();                      //  Leticia  // Ja esta Feita :)
    bool possui_articulacao();             //  Favio
    void DFSArticulacao(int v, bool visited[], int low[], int parent[], bool &articulacao);
    bool possui_ponte(); //  Favio

    static Grafo* carrega_grafo(const std::string& nomeArquivo); //  Lucas
    static void novo_grafo(const std::string& nomeArquivoEntrada, const std::string& nomeArquivoSaida); //  Lucas

    Grafo(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);
    ~Grafo();

    //funçoes auxiliares
    Vertice* getVertices();
    void adicionarAresta(int origem, int destino, int peso);
    void geraGrafoAleatorio(int grau, int nVertices, bool direcionado, int compConexas, bool ponderadoVertices, bool ponderadoArestas, bool completo, bool bipartido, bool arvore, bool arestaPonte, bool verticeArticulacao);
    bool ehConexo();
    int conta_componentes_conexos_removido(int verticeRemovido);
    bool temCicloDFS(int v, bool visitado[], int pai);

private:
    void DFS(int v, bool visited[]);
};

#endif
