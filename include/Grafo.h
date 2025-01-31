#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "Vertice.h"

class Grafo {
protected:
    Vertice* vertices;      // Lista de vértices
    int nVertices;          // Número de vértices (ordem) do grafo
    int grau;               // Grau do grafo (número de arestas do vertice que possui mais arestas)
    bool direcionado;       // Indica se o grafo é direcionado
    bool ponderadoVertices; // Indica se o grafo possui peso nos vertices
    bool ponderadoArestas;  // Indica se o grafo possui peso nas arestas

public:
    // Construtor e Destrutor
    Grafo(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);
    ~Grafo();

    // Funcoes principais
    int n_conexo();            //Retorna a quantidade total de componentes conexas do grafo
    int get_grau();            //Retorna o grau do grafo
    int get_ordem();           //Retorna a ordem do grafo (numero de vertices do grafo)
    bool eh_direcionado();     //Retorna se o grafo eh direcionado ou nao
    bool vertice_ponderado();  //Retorna se o grafo possui peso nos vertices ou nao
    bool aresta_ponderada();   //Retorna se o grafo possui peso nas arestas ou nao
    bool eh_completo();        //Verifica se o grafo eh completo ou nao

    virtual bool eh_bipartido() = 0;       //Verifica se o grafo eh bipartido ou nao
    virtual bool eh_arvore() = 0;          //Verifica se o grafo eh uma arvore ou nao
    virtual bool possui_articulacao() = 0; //Verifica se o grafo possui pelo menos 1 vertice de articulacao
    virtual bool possui_ponte() = 0;       //Verifica se o grafo possui pelo menos 1 aresta ponte

    // Funcao gera Grafo
    static void carrega_grafo(Grafo* grafo, const std::string& nomeArquivo);        //Gera um grafo a partir do arquivo grafo.txt
   
    //Funcao imprime
    void imprime();        //Imprime os atributos do grafo

    //Funcoes auxiliares
    virtual void adicionarAresta(int origem, int destino, int peso = 1) = 0;            //Adiciona uma aresta no grafo
    virtual void DFS(int v, bool visitado[]){};                                       //Percorre o grafo em profundidade
};

#endif
