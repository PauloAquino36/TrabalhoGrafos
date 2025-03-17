/**
 * @file GrafoLista.h
 * @brief Declaração da classe GrafoLista, que implementa grafos usando listas de adjacência.
 */

#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "Grafo.h"
#include "ListaAdjVertice.h"
#include "ListaAdjAresta.h"

/**
 * @class GrafoLista
 * @brief Representa um grafo utilizando listas de adjacência.
 *
 * A classe GrafoLista deriva de Grafo e implementa as operações de manipulação
 * e análise de grafos utilizando uma estrutura de listas encadeadas para armazenar
 * os vértices e suas respectivas arestas.
 */
class GrafoLista : public Grafo {
protected:
    ListaAdjVertice* listaAdjVertices;  ///< Lista encadeada de vértices.

public:
    /**
     * @brief Construtor da classe GrafoLista.
     * @param numVertices Número inicial de vértices.
     * @param direcionado Indica se o grafo é direcionado.
     * @param ponderadoVertices Indica se os vértices possuem peso.
     * @param ponderadoArestas Indica se as arestas possuem peso.
     */
    GrafoLista(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);

    /**
     * @brief Destrutor da classe GrafoLista.
     */
    ~GrafoLista();

    // Métodos auxiliares

    /**
     * @brief Retorna o número de vizinhos de um vértice.
     * @param id Identificador do vértice.
     * @return Número de vértices vizinhos.
     */
    int get_num_vizinhos(int id) override;

    /**
     * @brief Executa a busca em profundidade (DFS) a partir de um vértice.
     * @param id Vértice inicial.
     * @param visitado Vetor que marca os vértices visitados.
     */
    void dfs(int id, bool* visitado) override;

    /**
     * @brief Verifica se um vértice existe no grafo.
     * @param id Identificador do vértice.
     * @return True se o vértice existir, caso contrário, false.
     */
    bool existe_vertice(int id) override;

    // Métodos de manipulação de vértices e arestas

    /**
     * @brief Adiciona um vértice ao grafo.
     * @param id Identificador do novo vértice.
     * @param peso Peso do vértice (valor padrão 0.0).
     */
    void adicionar_vertice(int id, float peso = 0.0) override;

    /**
     * @brief Adiciona uma aresta ao grafo.
     * @param origem Identificador do vértice de origem.
     * @param destino Identificador do vértice de destino.
     * @param peso Peso da aresta (valor padrão 1.0).
     */
    void adicionar_aresta(int origem, int destino, float peso = 1.0) override;

    /**
     * @brief Remove um vértice do grafo.
     * @param id Identificador do vértice a ser removido.
     */
    void remover_vertice(int id) override;

    /**
     * @brief Remove uma aresta do grafo.
     * @param origem Identificador do vértice de origem.
     * @param destino Identificador do vértice de destino.
     */
    void remover_aresta(int origem, int destino) override;

    /**
     * @brief Remove a primeira aresta associada a um vértice.
     * @param id Identificador do vértice.
     */
    void remover_primeira_aresta(int id) override;

    /**
     * @brief Calcula a menor distância entre dois vértices.
     * @param origem Identificador do vértice de origem.
     * @param destino Identificador do vértice de destino.
     * @return Menor distância entre os vértices.
     */
    int calcula_menor_dist(int origem, int destino);

    // Métodos de impressão

    /**
     * @brief Imprime as informações do grafo.
     */
    void imprimeGrafoLista();

    /**
     * @brief Imprime a lista de adjacência do grafo.
     */
    void imprimeListaAdj();

    // Algoritmos gulosos para cobertura de vértices

    /**
     * @brief Executa o algoritmo guloso para cobertura de vértices.
     * @return Resultado do algoritmo (por exemplo, tamanho da cobertura).
     */
    int alg_guloso_cobertura_vertice() override;

    /**
     * @brief Executa o algoritmo randomizado para cobertura de vértices.
     * @return Resultado do algoritmo.
     */
    int alg_randomizado_cobertura_vertice() override;

    /**
     * @brief Executa o algoritmo reativo para cobertura de vértices.
     * @return Resultado do algoritmo.
     */
    int alg_reativo_cobertura_vertice() override;
};

#endif // GRAFO_LISTA_H
