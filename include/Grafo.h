#ifndef GRAFO_H
#define GRAFO_H

#include "../include/ListaAdjAresta.h"
#include "../include/ListaAdjVertice.h"
#include <iostream>

using namespace std;

class Grafo {
protected:
    int numVertices;                    // Numero de vertices (ordem) do grafo
    int numArestasGrafo;                // Numero de arestas do grafo
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
    void imprimir_descricao();                     // Imprime os atributos do grafo
    void imprimir_algoritmos_cobertura_vertice(Grafo* grafo);  // Imprime algoritmos gulosos para cobertura de vertices

    // Funcoes auxiliares abstratas que estao implementadas nas classes filhas
    virtual ListaAdjAresta* get_vizinhos(int id) { return nullptr; };               // Retorna os vertices vizinhos de um vertice     
    virtual int get_num_vizinhos(int id) { return 0; };                             // Retorna o numero de vizinhos de um vertice
    virtual void dfs(int v, bool* visitado){};                                      // Realiza a busca em profundidade
    virtual bool existe_vertice(int id)=0;                                          // Verifica se um vertice existe
    int get_num_arestas_grafo();                                                    // Retorna o numero de arestas do grafo
    void incrementa_num_vertices_grafo();                                           // Incrementa o numero de vertices do grafo
    void decrementa_num_vertices_grafo();                                           // Decrementa o numero de vertices do grafo
    void incrementa_num_arestas_grafos();                                           // Incrementa o numero de arestas do grafo
    void decrementa_num_arestas_grafos();                                           // Decrementa o numero de arestas do grafo
    void diminui_num_arestas_grafos(int valor);                                     // Diminui o numero de arestas do grafo

    // Funcoes de manipulacao de vertices e arestas abstratas que estao implementadas nas classes filhas
    virtual void adicionar_vertice(int id, float peso = 0.0){};                     // Adiciona um vertice no grafo
    virtual void adicionar_aresta(int origem, int destino, float peso = 1.0){};     // Adiciona uma aresta no grafo
    virtual void remover_primeira_aresta(int id){};                                 // Remove a primeira aresta de um vertice
    virtual void remover_vertice(int id){};                                         // Remove um vertice do grafo
    virtual void remover_aresta(int origem, int destino){};                         // Remove uma aresta do grafo

    // Funcoes de calculo de menor distancia abstratas que estao implementadas nas classes filhas
    virtual int calcula_menor_dist(int origem, int destino)=0;                      // Calcula a menor distancia entre dois vertices
    virtual int calcula_maior_menor_dist();                                         // Calcula a maior menor distancia entre dois vertices

    // Funcoes da solucao de cobertura de vertice que estao implementadas nas classes filhas
    virtual void alg_guloso_cobertura_vertice(){};                                  // Algoritmo guloso para cobertura de vertices
    virtual void alg_randomizado_cobertura_vertice(){};                             // Algoritmo randomizado para cobertura de vertices
    virtual void alg_reativo_cobertura_vertice(){};                                 // Algoritmo reativo para cobertura de vertices
};

#endif
