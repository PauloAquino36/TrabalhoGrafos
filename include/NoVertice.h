#ifndef NO_VERTICE_H
#define NO_VERTICE_H

#include "ListaAdjAresta.h"
#include "NoAresta.h"

/**
 * @class NoVertice
 * @brief Classe que representa um nó de vértice em uma lista de adjacência.
 */
class NoVertice {
private:
    int idVertice;              ///< Identificador do vertice
    float peso;                 ///< Peso do vertice
    int numArestas;             ///< Numero de arestas do vertice (quantidade de vertices vizinhos)
    NoVertice* proximo;         ///< Ponteiro para o proximo no vertice
    ListaAdjAresta* arestas;    ///< Lista encadeada de arestas

public:
    /**
     * @brief Construtor da classe NoVertice.
     * @param vertice Identificador do vertice.
     * @param peso Peso do vertice.
     */
    NoVertice(int vertice, float peso);

    /**
     * @brief Destrutor da classe NoVertice.
     */
    ~NoVertice();

    /**
     * @brief Retorna o identificador do vertice.
     * @return Identificador do vertice.
     */
    int getIdVertice();

    /**
     * @brief Retorna o peso do vertice.
     * @return Peso do vertice.
     */
    float getPesoVertice();

    /**
     * @brief Retorna a quantidade de arestas do vertice.
     * @return Numero de arestas do vertice.
     */
    int getNumArestas();

    /**
     * @brief Retorna o proximo no vertice.
     * @return Ponteiro para o proximo no vertice.
     */
    NoVertice* getProximo();

    /**
     * @brief Retorna a lista encadeada de arestas.
     * @return Ponteiro para a lista de arestas.
     */
    ListaAdjAresta* getArestas();

    /**
     * @brief Define o proximo no vertice.
     * @param proximo Ponteiro para o proximo no vertice.
     */
    void setProximo(NoVertice* proximo);

    /**
     * @brief Define o identificador do vertice.
     * @param novoId Novo identificador do vertice.
     */
    int setIdVertice(int novoId);

    /**
     * @brief Retorna o numero de vizinhos do vertice (numero de arestas de saida/ grau do vertice).
     * @return Numero de vizinhos do vertice.
     */
    int getNumVizinhos();

    /**
     * @brief Adiciona uma aresta ao vertice.
     * @param id Identificador do vertice de destino.
     * @param peso Peso da aresta.
     */
    void adicionar_aresta(int id, float peso);

    /**
     * @brief Remove uma aresta do vertice.
     * @param destino Identificador do vertice de destino.
     */
    void remover_aresta(int destino);

    /**
     * @brief Remove a primeira aresta do vertice.
     */
    void remover_primeira_aresta();
};

#endif // NO_VERTICE_H