#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H

#include "Grafo.h"
#include "Vertice.h"

class GrafoMatriz  : public Grafo {
protected:
    int** matrizAdj;  // Matriz de adjacência

public:
    // Contrutor e Destrutor
    GrafoMatriz(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);
    ~GrafoMatriz();

    // Funcoes principais
    bool eh_bipartido() override;
    bool eh_arvore() override;
    bool possui_articulacao() override;
    bool possui_ponte() override;

    // Funções auxiliares
    int grauVertice(int vertice);
    Vertice& getVertice(int vertice);                                   //Retorna um vertice especifico do grafo
    void adicionarAresta(int origem, int destino, int peso = 1) override;        //Adiciona uma aresta no grafo
    bool verificarParticaoBipartida(int v, int subconjunto[]);          //Funcao auxiliar para verificar se o grafo é bipartido
    bool ehConexo();                                                    //Verifica se o grafo eh conexo ou nao
    void DFS(int v, bool visitado[]);                                   //Percorre o grafo em profundidade
    bool temCicloDFS(int v, bool visitado[], int pai);                  //Verifica se o grafo possui ciclo
    void DFSPonte(int v, bool visitado[], int discovery[], int low[], int parent[], bool& ponteEncontrada); //Funcao auxiliar para a funcao possui_ponte
    void DFSArticulacao(int i, bool visitado[],int discovery[],int low[],int parent[],bool& articulacaoEncontrada); //Funcao auxiliar para a funcao possui_articulacao
    
    // Funcoes de imprimir
    void imprimirMatrizAdj();                                           //Imprime a matriz de adjacência
    void imprimeGrafoMatriz();                                          //Imprime os atributos do grafo
};

#endif // GRAFOMATRIZ_H