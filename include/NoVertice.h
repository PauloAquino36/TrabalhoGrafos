/**
 * @file NoVertice.h
 * @brief Declaração da classe NoVertice, que representa um nó em uma lista de vértices.
 */

#ifndef NO_VERTICE_H
#define NO_VERTICE_H

#include "ListaAdjAresta.h"
#include "NoAresta.h"

class GrafoLista;  // Declaração antecipada

/**
 * @class NoVertice
 * @brief Representa um vértice em uma lista encadeada com suas arestas associadas.
 */
class NoVertice {
private:
    int idVertice;             ///< Identificador do vértice.
    float peso;                ///< Peso do vértice.
    int numArestasVertice;     ///< Número de arestas (grau) do vértice.
    NoVertice* proximo;        ///< Ponteiro para o próximo nó de vértice.
    ListaAdjAresta* arestas;   ///< Lista encadeada de arestas associadas ao vértice.
    GrafoLista* grafo;         ///< Ponteiro para o grafo ao qual o vértice pertence.

public:
    /**
     * @brief Construtor da classe NoVertice.
     * @param vertice Identificador do vértice.
     * @param peso Peso do vértice.
     * @param grafo Ponteiro para o grafo (GrafoLista) que contém o vértice.
     */
    NoVertice(int vertice, float peso, GrafoLista* grafo);

    /**
     * @brief Destrutor da classe NoVertice.
     */
    ~NoVertice();

    // Getters e Setters

    /**
     * @brief Retorna o identificador do vértice.
     * @return ID do vértice.
     */
    int getIdVertice();

    /**
     * @brief Retorna o peso do vértice.
     * @return Peso do vértice.
     */
    float getPesoVertice();

    /**
     * @brief Retorna a quantidade de arestas (grau) do vértice.
     * @return Número de arestas.
     */
    int getNumArestasVertice();

    /**
     * @brief Retorna o próximo nó de vértice na lista.
     * @return Ponteiro para o próximo NoVertice.
     */
    NoVertice* getProximo();

    /**
     * @brief Retorna a lista encadeada de arestas associadas ao vértice.
     * @return Ponteiro para a ListaAdjAresta.
     */
    ListaAdjAresta* getArestas();

    /**
     * @brief Define o próximo nó de vértice na lista.
     * @param proximo Ponteiro para o novo próximo nó.
     */
    void setProximo(NoVertice* proximo);

    /**
     * @brief Define um novo identificador para o vértice.
     * @param novoId Novo ID do vértice.
     * @return O novo identificador atribuído.
     */
    int setIdVertice(int novoId);

    // Métodos auxiliares

    /**
     * @brief Retorna o número de vizinhos (grau) do vértice.
     * @return Número de vizinhos.
     */
    int getNumVizinhos();

    /**
     * @brief Adiciona uma aresta ao vértice.
     * @param id Identificador do vértice de destino da nova aresta.
     * @param peso Peso da aresta.
     */
    void adicionar_aresta(int id, float peso);

    /**
     * @brief Remove uma aresta do vértice.
     * @param destino Identificador do vértice de destino da aresta a ser removida.
     */
    void remover_aresta(int destino);

    /**
     * @brief Remove a primeira aresta associada ao vértice.
     */
    void remover_primeira_aresta();

    /**
     * @brief Retorna o identificador da aresta que conecta este vértice a outro.
     * @param destino Identificador do vértice de destino.
     * @return ID da aresta.
     */
    int getIdAresta(int destino);
};

#endif // NO_VERTICE_H
