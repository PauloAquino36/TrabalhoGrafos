/**
 * @file GrafoMatriz.h
 * @brief Declaração da classe GrafoMatriz, que implementa grafos usando matriz de adjacência.
 */

#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H

#include "Grafo.h"
#include <vector>

/**
 * @class GrafoMatriz
 * @brief Representa um grafo utilizando uma matriz de adjacência.
 *
 * A classe GrafoMatriz implementa as operações de manipulação e análise de grafos
 * utilizando uma matriz para armazenar as conexões entre vértices.
 */
class GrafoMatriz : public Grafo {
protected:
    int** matrizAdj;       ///< Matriz de adjacência.
    int tamanhoMatriz;     ///< Tamanho da matriz (número de vértices, considerado MXM).

public:
    /**
     * @brief Construtor da classe GrafoMatriz.
     * @param numVertices Número de vértices do grafo.
     * @param direcionado Indica se o grafo é direcionado.
     * @param ponderadoVertices Indica se os vértices possuem peso.
     * @param ponderadoArestas Indica se as arestas possuem peso.
     */
    GrafoMatriz(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);

    /**
     * @brief Destrutor da classe GrafoMatriz.
     */
    ~GrafoMatriz();

    // Métodos auxiliares

    /**
     * @brief Retorna o grau (número de conexões) de um vértice.
     * @param vertice Identificador do vértice.
     * @return Grau do vértice.
     */
    int grauVertice(int vertice);

    /**
     * @brief Retorna o número de vizinhos de um vértice.
     * @param id Identificador do vértice.
     * @return Número de vizinhos.
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
    int calcula_menor_dist(int origem, int destino) override;

    // Métodos de impressão

    /**
     * @brief Imprime a matriz de adjacência.
     */
    void imprimirMatrizAdj();

    /**
     * @brief Imprime os atributos do grafo.
     */
    void imprimeGrafoMatriz();

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

    /**
     * @brief Executa o algoritmo randomizado para cobertura de vértices utilizando um parâmetro alpha.
     * @param alpha Parâmetro que influencia a aleatoriedade do algoritmo.
     * @return Resultado do algoritmo.
     */
    int alg_randomizado_cobertura_vertice_com_alpha(double alpha);
};

#endif // GRAFOMATRIZ_H
