#ifndef GRAFO_H
#define GRAFO_H

#include "../include/ListaAdjAresta.h"
#include "../include/ListaAdjVertice.h"
#include <iostream>

using namespace std;

/**
 * @class Grafo
 * @brief Classe base para representar um grafo.
 */
class Grafo {
protected:
    int numVertices;                    ///< Numero de vertices (ordem) do grafo
    bool direcionado;                   ///< Indica se o grafo eh direcionado
    bool ponderadoVertices;             ///< Indica se o grafo possui peso nos vertices
    bool ponderadoArestas;              ///< Indica se o grafo possui peso nas arestas

public:
    /**
     * @brief Construtor da classe Grafo.
     * @param numVertices Numero de vertices do grafo.
     * @param direcionado Indica se o grafo eh direcionado.
     * @param ponderadoVertices Indica se o grafo possui peso nos vertices.
     * @param ponderadoArestas Indica se o grafo possui peso nas arestas.
     */
    Grafo(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);

    /**
     * @brief Destrutor da classe Grafo.
     */
    ~Grafo();

    /**
     * @brief Retorna a quantidade total de componentes conexas do grafo.
     * @return Numero de componentes conexas.
     */
    int n_conexo();

    /**
     * @brief Retorna o grau do grafo.
     * @return Grau do grafo.
     */
    int get_grau();

    /**
     * @brief Retorna a ordem do grafo (numero de vertices do grafo).
     * @return Ordem do grafo.
     */
    int get_ordem();

    /**
     * @brief Retorna se o grafo eh direcionado ou nao.
     * @return True se o grafo eh direcionado, false caso contrario.
     */
    bool eh_direcionado();

    /**
     * @brief Retorna se o grafo possui peso nos vertices ou nao.
     * @return True se o grafo possui peso nos vertices, false caso contrario.
     */
    bool vertice_ponderado();

    /**
     * @brief Retorna se o grafo possui peso nas arestas ou nao.
     * @return True se o grafo possui peso nas arestas, false caso contrario.
     */
    bool aresta_ponderada();

    /**
     * @brief Verifica se o grafo eh completo ou nao.
     * @return True se o grafo eh completo, false caso contrario.
     */
    bool eh_completo();

    /**
     * @brief Gera um grafo a partir do arquivo grafo.txt.
     * @param grafo Ponteiro para o objeto Grafo.
     * @param nomeArquivo Nome do arquivo que contem o grafo.
     */
    static void carrega_grafo(Grafo* grafo, const string& nomeArquivo);

    /**
     * @brief Imprime os atributos do grafo.
     */
    void imprime();

    // Funcoes auxiliares abstratas que serao implementadas nas classes filhas
    virtual ListaAdjAresta* get_vizinhos(int id) { return nullptr; };
    virtual int get_num_vizinhos(int id) { return 0; };
    virtual void dfs(int v, bool* visitado){};
    virtual bool existe_vertice(int id)=0;

    // Funcoes de manipulacao de vertices e arestas abstratas que serao implementadas nas classes filhas
    virtual void adicionar_vertice(int id, float peso = 0.0){};
    virtual void adicionar_aresta(int origem, int destino, float peso = 1.0){};
    virtual void remover_primeira_aresta(int id){};
    virtual void remover_vertice(int id){};
    virtual void remover_aresta(int origem, int destino){};

    virtual int calcula_menor_dist(int origem, int destino)=0;
    virtual int calcula_maior_menor_dist()=0;
};

#endif