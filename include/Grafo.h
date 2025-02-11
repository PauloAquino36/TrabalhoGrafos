#ifndef GRAFO_H
#define GRAFO_H

#include "../include/ListaAdjAresta.h"
#include "../include/ListaAdjVertice.h"
#include <iostream>

using namespace std;

class Grafo {
protected:
    int numVertices;                    // Numero de vertices (ordem) do grafo
    bool direcionado;                   // Indica se o grafo eh direcionado
    bool ponderadoVertices;             // Indica se o grafo possui peso nos vertices
    bool ponderadoArestas;              // Indica se o grafo possui peso nas arestas

public:
    // Construtor e Destrutor
    Grafo(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);
    ~Grafo();

    // Funcoes principais
    int n_conexo();                     // Retorna a quantidade total de componentes conexas do grafo
    int get_grau();                     // Retorna o grau do grafo
    int get_ordem();                    // Retorna a ordem do grafo (numero de vertices do grafo)
    bool eh_direcionado();              // Retorna se o grafo eh direcionado ou nao
    bool vertice_ponderado();           // Retorna se o grafo possui peso nos vertices ou nao
    bool aresta_ponderada();            // Retorna se o grafo possui peso nas arestas ou nao
    bool eh_completo();                 // Verifica se o grafo eh completo ou nao

    // Funcao gera grafo
    static void carrega_grafo(Grafo* grafo, const string& nomeArquivo);             // Gera um grafo a partir do arquivo grafo.txt
   
    // Funcao imprime
    void imprime();                     // Imprime os atributos do grafo

    // Funcoes auxiliares abstratas que serao implementadas nas classes filhas
    virtual ListaAdjAresta* get_vizinhos(int id) { return nullptr; };               // Retorna os vertices vizinhos de um vertice     
    virtual int get_num_vizinhos(int id) { return 0; };                             // Retorna o numero de vizinhos de um vertice
    virtual void dfs(int v, bool* visitado){};                                      // Realiza a busca em profundidade
    virtual bool existe_vertice(int id)=0;                                          // Verifica se um vertice existe

    // Funcoes de manipulacao de vertices e arestas abstratas que serao implementadas nas classes filhas
    virtual void adicionar_vertice(int id, float peso = 0.0){};                     // Adiciona um vertice no grafo
    virtual void adicionar_aresta(int origem, int destino, float peso = 1.0){};     // Adiciona uma aresta no grafo
    virtual void remover_primeira_aresta(int id){};                                 // Remove a primeira aresta de um vertice
    virtual void remover_vertice(int id){};                                         // Remove um vertice do grafo
    virtual void remover_aresta(int origem, int destino){};                         // Remove uma aresta do grafo

    virtual int calcula_menor_dist(int origem, int destino)=0;                      // Calcula a menor distancia entre dois vertices
    virtual int calcula_maior_menor_dist();                                       // Calcula a maior menor distancia entre dois vertices
};

#endif
