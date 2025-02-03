#include "Grafo.h"
#include "ListaAdjVertice.h"
#include "ListaAdjAresta.h"

#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

class GrafoLista : public Grafo {
protected:
    ListaAdjVertice* listaAdjVertices; // Lista de adjacência
public:
    //Construtor e Destrutor
    GrafoLista(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);
    ~GrafoLista();

    //Funcoes auxiliares
    void atualiza_grafo(int numVertices) override;                               //Atualiza o grafo
    void adicionar_vertice(int id, int peso = 0) override;                       //Adiciona um vertice no grafo
    void adicionar_aresta(int origem, int destino, int peso = 0) override;       //Adiciona uma aresta no grafo
    ListaAdjAresta* get_vizinhos(int id) override;                               //Retorna os vertices vizinhos de um vertice
    int get_num_vizinhos(int id) override;                                       //Retorna o numero de vizinhos de um vertice
    void dfs(int id, bool* visitado) override;                                    //Realiza a busca em profundidade

    //Funcoes imprime
    void imprimeGrafoLista();                                                   //Imprime as informacoes do grafo
    void imprimeListaAdj();                                                     //Imprime a lista de adjacência
    

    void removerAresta(int origem, int destino);                               //Remove uma aresta do grafo
    
};

#endif // GRAFOLISTA_H