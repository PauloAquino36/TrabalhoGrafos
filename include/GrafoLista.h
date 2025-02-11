#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "Grafo.h"
#include "ListaAdjVertice.h"
#include "ListaAdjAresta.h"

/**
 * @class GrafoLista
 * @brief Classe que representa um grafo utilizando lista de adjacência.
 */
class GrafoLista : public Grafo {
protected:
    ListaAdjVertice* listaAdjVertices;  ///< Lista encadeada de vertices

public:
    /**
     * @brief Construtor da classe GrafoLista.
     * @param numVertices Numero de vertices do grafo.
     * @param direcionado Indica se o grafo eh direcionado.
     * @param ponderadoVertices Indica se o grafo possui peso nos vertices.
     * @param ponderadoArestas Indica se o grafo possui peso nas arestas.
     */
    GrafoLista(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);

    /**
     * @brief Destrutor da classe GrafoLista.
     */
    ~GrafoLista();

    /**
     * @brief Retorna o numero de vizinhos de um vertice do grafo.
     * @param id Identificador do vertice.
     * @return Numero de vizinhos do vertice.
     */
    int get_num_vizinhos(int id) override;

    /**
     * @brief Realiza a busca em profundidade no grafo.
     * @param id Identificador do vertice inicial.
     * @param visitado Vetor de vertices visitados.
     */
    void dfs(int id, bool* visitado) override;

    /**
     * @brief Verifica se um vertice existe no grafo.
     * @param id Identificador do vertice.
     * @return True se o vertice existe, false caso contrario.
     */
    bool existe_vertice(int id) override;

    /**
     * @brief Adiciona um vertice no grafo.
     * @param id Identificador do vertice.
     * @param peso Peso do vertice (opcional).
     */
    void adicionar_vertice(int id, float peso = 0.0) override;

    /**
     * @brief Adiciona uma aresta no grafo.
     * @param origem Identificador do vertice de origem.
     * @param destino Identificador do vertice de destino.
     * @param peso Peso da aresta (opcional).
     */
    void adicionar_aresta(int origem, int destino, float peso = 1.0) override;

    /**
     * @brief Remove um vertice do grafo.
     * @param id Identificador do vertice.
     */
    void remover_vertice(int id) override;

    /**
     * @brief Remove uma aresta do grafo.
     * @param origem Identificador do vertice de origem.
     * @param destino Identificador do vertice de destino.
     */
    void remover_aresta(int origem, int destino) override;

    /**
     * @brief Remove a primeira aresta de um vertice.
     * @param id Identificador do vertice.
     */
    void remover_primeira_aresta(int id) override;

    /**
     * @brief Calcula a menor distancia entre dois vertices.
     * @param origem Identificador do vertice de origem.
     * @param destino Identificador do vertice de destino.
     * @return Menor distancia entre os vertices.
     */
    int calcula_menor_dist(int origem, int destino);

    /**
     * @brief Calcula a maior entre as menores distancias de um grafo.
     * @return Maior entre as menores distancias.
     */
    int calcula_maior_menor_dist();

    /**
     * @brief Imprime as informacoes do grafo.
     */
    void imprimeGrafoLista();

    /**
     * @brief Imprime a lista de adjacencia.
     */
    void imprimeListaAdj();
};

#endif // GRAFO_LISTA_H