/**
 * @file Grafo.h
 * @brief Declaração da classe base para representação de grafos.
 */

#ifndef GRAFO_H
#define GRAFO_H

#include "../include/ListaAdjAresta.h"
#include "../include/ListaAdjVertice.h"
#include <iostream>

using namespace std;

/**
 * @class Grafo
 * @brief Representa um grafo com propriedades básicas.
 *
 * A classe Grafo contém os atributos e métodos essenciais para definir
 * um grafo, como o número de vértices, número de arestas, e flags que indicam
 * se o grafo é direcionado ou se possui pesos em seus vértices e arestas.
 * Métodos abstratos para manipulação e análise de grafos devem ser implementados
 * pelas classes derivadas.
 */
class Grafo {
protected:
    int numVertices;                    ///< Número de vértices (ordem) do grafo.
    int numArestasGrafo;                ///< Número de arestas do grafo.
    bool direcionado;                   ///< Indica se o grafo é direcionado.
    bool ponderadoVertices;             ///< Indica se o grafo possui peso nos vértices.
    bool ponderadoArestas;              ///< Indica se o grafo possui peso nas arestas.

public:
    /**
     * @brief Construtor da classe Grafo.
     * @param numVertices Número de vértices do grafo.
     * @param direcionado Indica se o grafo é direcionado.
     * @param ponderadoVertices Indica se os vértices possuem peso.
     * @param ponderadoArestas Indica se as arestas possuem peso.
     */
    Grafo(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);

    /**
     * @brief Destrutor da classe Grafo.
     */
    ~Grafo();

    // Métodos principais

    /**
     * @brief Retorna a quantidade total de componentes conexas do grafo.
     * @return Número de componentes conexas.
     */
    int n_conexo();

    /**
     * @brief Retorna o grau do grafo.
     * @return Grau do grafo.
     */
    int get_grau();

    /**
     * @brief Retorna a ordem do grafo (número de vértices).
     * @return Ordem do grafo.
     */
    int get_ordem();

    /**
     * @brief Verifica se o grafo é direcionado.
     * @return True se for direcionado, caso contrário, false.
     */
    bool eh_direcionado();

    /**
     * @brief Verifica se o grafo possui peso nos vértices.
     * @return True se os vértices são ponderados, caso contrário, false.
     */
    bool vertice_ponderado();

    /**
     * @brief Verifica se o grafo possui peso nas arestas.
     * @return True se as arestas são ponderadas, caso contrário, false.
     */
    bool aresta_ponderada();

    /**
     * @brief Verifica se o grafo é completo.
     * @return True se o grafo for completo, caso contrário, false.
     */
    bool eh_completo();

    // Função para geração de grafo

    /**
     * @brief Carrega um grafo a partir de um arquivo.
     * @param grafo Ponteiro para o objeto Grafo.
     * @param nomeArquivo Nome do arquivo que contém a descrição do grafo.
     */
    static void carrega_grafo(Grafo* grafo, const string& nomeArquivo);

    // Funções de impressão

    /**
     * @brief Imprime os atributos básicos do grafo.
     */
    void imprimir_descricao();

    /**
     * @brief Imprime os resultados dos algoritmos gulosos para cobertura de vértices.
     * @param grafo Ponteiro para o objeto Grafo.
     */
    void imprimir_algoritmos_cobertura_vertice(Grafo* grafo);

    /**
     * @brief Analisa os algoritmos gulosos para cobertura de vértices.
     * @param grafo Ponteiro para o objeto Grafo.
     * @param numVezes Número de vezes a serem executados os algoritmos.
     */
    void analise_algoritmos_cobertura_vertice(Grafo* grafo, int numVezes);

    // Métodos auxiliares abstratos a serem implementados nas classes derivadas

    /**
     * @brief Retorna os vértices vizinhos de um vértice.
     * @param id Identificador do vértice.
     * @return Ponteiro para a lista de adjacência de arestas dos vizinhos.
     */
    virtual ListaAdjAresta* get_vizinhos(int id) { return nullptr; };

    /**
     * @brief Retorna o número de vértices vizinhos de um vértice.
     * @param id Identificador do vértice.
     * @return Número de vizinhos.
     */
    virtual int get_num_vizinhos(int id) { return 0; };

    /**
     * @brief Realiza a busca em profundidade (DFS) a partir de um vértice.
     * @param v Vértice inicial.
     * @param visitado Vetor indicando os vértices já visitados.
     */
    virtual void dfs(int v, bool* visitado){};

    /**
     * @brief Verifica se um vértice existe no grafo.
     * @param id Identificador do vértice.
     * @return True se o vértice existir, caso contrário, false.
     */
    virtual bool existe_vertice(int id)=0;

    /**
     * @brief Retorna o número de arestas do grafo.
     * @return Número de arestas.
     */
    int get_num_arestas_grafo();

    /**
     * @brief Incrementa o número de vértices do grafo.
     */
    void incrementa_num_vertices_grafo();

    /**
     * @brief Decrementa o número de vértices do grafo.
     */
    void decrementa_num_vertices_grafo();

    /**
     * @brief Incrementa o número de arestas do grafo.
     */
    void incrementa_num_arestas_grafos();

    /**
     * @brief Decrementa o número de arestas do grafo.
     */
    void decrementa_num_arestas_grafos();

    /**
     * @brief Diminui o número de arestas do grafo por um valor especificado.
     * @param valor Valor a ser subtraído do total de arestas.
     */
    void diminui_num_arestas_grafos(int valor);

    // Métodos abstratos de manipulação de vértices e arestas

    /**
     * @brief Adiciona um vértice ao grafo.
     * @param id Identificador do vértice.
     * @param peso Peso do vértice (valor padrão 0.0).
     */
    virtual void adicionar_vertice(int id, float peso = 0.0){};

    /**
     * @brief Adiciona uma aresta ao grafo.
     * @param origem Identificador do vértice de origem.
     * @param destino Identificador do vértice de destino.
     * @param peso Peso da aresta (valor padrão 1.0).
     */
    virtual void adicionar_aresta(int origem, int destino, float peso = 1.0){};

    /**
     * @brief Remove a primeira aresta associada a um vértice.
     * @param id Identificador do vértice.
     */
    virtual void remover_primeira_aresta(int id){};

    /**
     * @brief Remove um vértice do grafo.
     * @param id Identificador do vértice a ser removido.
     */
    virtual void remover_vertice(int id){};

    /**
     * @brief Remove uma aresta do grafo.
     * @param origem Identificador do vértice de origem.
     * @param destino Identificador do vértice de destino.
     */
    virtual void remover_aresta(int origem, int destino){};

    // Métodos abstratos para cálculo de distâncias

    /**
     * @brief Calcula a menor distância entre dois vértices.
     * @param origem Identificador do vértice de origem.
     * @param destino Identificador do vértice de destino.
     * @return Menor distância entre os vértices.
     */
    virtual int calcula_menor_dist(int origem, int destino)=0;

    /**
     * @brief Calcula a maior dentre as menores distâncias entre pares de vértices.
     * @return A maior das menores distâncias encontradas.
     */
    virtual int calcula_maior_menor_dist();

    // Métodos abstratos para algoritmos de cobertura de vértices

    /**
     * @brief Executa o algoritmo guloso para cobertura de vértices.
     * @return Resultado do algoritmo (por exemplo, tamanho da cobertura).
     */
    virtual int alg_guloso_cobertura_vertice() = 0;

    /**
     * @brief Executa o algoritmo randomizado para cobertura de vértices.
     * @return Resultado do algoritmo.
     */
    virtual int alg_randomizado_cobertura_vertice() = 0;

    /**
     * @brief Executa o algoritmo reativo para cobertura de vértices.
     * @return Resultado do algoritmo.
     */
    virtual int alg_reativo_cobertura_vertice() = 0;
};

#endif // GRAFO_H
