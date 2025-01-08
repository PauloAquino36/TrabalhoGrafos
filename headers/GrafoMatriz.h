#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H

#include "Grafo.h"
#include "Vertice.h"

class GrafoMatriz  : public Grafo {
protected:
    int** matrizAdj;  // Matriz de adjacência

public:
    //Contrutor e Destrutor
    GrafoMatriz(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);
    ~GrafoMatriz();

    //Funcoes principais
    bool eh_bipartido() override;
    int n_conexo() override;
    int get_grau() override;
    //int get_ordem() override;
    //bool eh_direcionado() override;
    //bool vertice_ponderado() override;
    //bool aresta_ponderada() override;
    //bool eh_completo() override;
    //bool eh_arvore() override;
    //bool possui_articulacao() override;
    //bool possui_ponte() override;

    //Funcoes gera grafo
    static GrafoMatriz* carrega_grafo(const std::string& nomeArquivo);

    // Funções auxiliares
    int** getVertices();        //Retorna os vertices do grafo
    void adicionarAresta(int origem, int destino, int peso = 1);    //Adiciona uma aresta no grafo
    bool ehConexo();            //Verifica se o grafo eh conexo ou nao
    void DFS(int v, bool visitado[]);       //Percorre o grafo em profundidade
    bool temCicloDFS(int v, bool visitado[], int pai);      //Verifica se o grafo possui ciclo
    void imprimirMatrizAdj();
    void imprimeGrafoMatriz();
    Vertice& getVertice(int vertice);
};

#endif // GRAFOMATRIZ_H