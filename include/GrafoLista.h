#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "Grafo.h"
#include "Vertice.h"
class GrafoLista : public Grafo {
protected:
    Vertice* vertices;      // Lista de vertices
public:
    //Construtor e Destrutor
    GrafoLista(int nVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);
    ~GrafoLista();

    //Funcoes principais
    bool eh_bipartido() override;
    bool eh_arvore() override;
    bool possui_articulacao() override;
    bool possui_ponte() override;

    //Funcoes auxiliares
    Vertice* getVertices();             //Retorna o vetor de vertices do grafo
    void adicionarAresta(int origem, int destino, int peso) override;    //Adiciona uma aresta no grafo
    void removerAresta(int origem, int destino);                 //Remove uma aresta do grafo
    bool verificarParticaoBipartida(int v, int subconjunto[]);
    bool ehConexo();                    //Verifica se o grafo eh conexo ou nao
    void DFS(int v, bool visitado[]);   //Percorre o grafo em profundidade
    void DFS_Ponte(int v, bool visited[], int discovery[], int low[], int parent[], bool& ponteEncontrada);     //Funcao auxiliar para a funcao possui_ponte
    void DFSArticulacao(int v, bool visited[], int low[], int parent[], bool &articulacao);                     //Funcao auxiliar para a funcao possui_articulacao
    bool temCicloDFS(int v, bool visitado[], int pai);      //Verifica se o grafo possui ciclo

    //Funcoes de imprimir
    void imprimeGrafoLista();
};

#endif // GRAFOLISTA_H