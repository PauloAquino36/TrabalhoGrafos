#ifndef GRAFO_MATRIZ_H    // Verifica se GRAFO_MATRIZ_H ainda não foi definido
#define GRAFO_MATRIZ_H    // Define GRAFO_MATRIZ_H para evitar múltiplas inclusões

#include "Grafo.h" 

class GrafoMatriz : public Grafo {
private:
    int **matrizAdj;
    int numVertices;
    bool direcionado;

public:
    GrafoMatriz(int nVertices, bool direcionado);
    ~GrafoMatriz();

    bool eh_bipartido();
    int n_conexo();
    int get_grau();
    int get_ordem();
    bool eh_direcionado();
    bool vertice_ponderado();
    bool aresta_ponderada();
    bool eh_completo();
    bool eh_arvore();
    bool possui_articulacao();
    bool possui_ponte();

    // Funções auxiliares para manipulação da matriz
    void adicionar_aresta(int vertice1, int vertice2, int peso);
    void remover_aresta(int vertice1, int vertice2);
    void imprimir() const;
};

#endif
