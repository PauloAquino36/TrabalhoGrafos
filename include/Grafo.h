#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "../include/ListaAdjAresta.h"
#include "../include/ListaAdjVertice.h"

class Grafo {
protected:
    int numVertices;                    // Número de vértices (ordem) do grafo
    bool direcionado;                   // Indica se o grafo é direcionado
    bool ponderadoVertices;             // Indica se o grafo possui peso nos vertices
    bool ponderadoArestas;              // Indica se o grafo possui peso nas arestas

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

    // Funcao gera Grafo
    static void carrega_grafo(Grafo* grafo, const std::string& nomeArquivo);        //Gera um grafo a partir do arquivo grafo.txt
   
    //Funcao imprime
    void imprime();        //Imprime os atributos do grafo

    //Funcoes auxiliares abstratas que serao implementadas nas classes filhas
    virtual void atualiza_grafo(int numVertices){};                                     //Atualiza o numero de vertices do grafo
    virtual void adicionar_aresta(int origem, int destino, int peso = 1){};             //Adiciona uma aresta no grafo
    virtual void adicionar_vertice(int id, int peso = 0){};                             //Adiciona um vertice no grafo  
    virtual ListaAdjAresta* get_vizinhos(int id){};                                     //Retorna os vertices vizinhos de um vertice
    virtual int get_num_vizinhos(int id){};                                             //Retorna o numero de vizinhos de um vertice
    virtual void dfs(int v, bool* visitado){};
};

#endif
