/**
 * @file NoAresta.h
 * @brief Declaração da classe NoAresta, que representa um nó em uma lista de arestas.
 */

#ifndef NO_ARESTA_H
#define NO_ARESTA_H

/**
 * @class NoAresta
 * @brief Representa uma aresta em uma lista encadeada.
 */
class NoAresta {
private:
    int idAresta;            ///< Identificador da aresta.
    int idVerticeOrigem;     ///< Identificador do vértice de origem.
    int idVerticeDestino;    ///< Identificador do vértice de destino.
    float peso;              ///< Peso da aresta.
    NoAresta* proximo;       ///< Ponteiro para o próximo nó de aresta.

public:
    /**
     * @brief Construtor da classe NoAresta.
     * @param idVerticeOrigem Identificador do vértice de origem.
     * @param idVerticeDestino Identificador do vértice de destino.
     * @param peso Peso da aresta.
     * @param idAresta Identificador único da aresta.
     */
    NoAresta(int idVerticeOrigem, int idVerticeDestino, float peso, int idAresta);

    /**
     * @brief Destrutor da classe NoAresta.
     */
    ~NoAresta();

    /**
     * @brief Retorna o identificador da aresta.
     * @return ID da aresta.
     */
    int getIdAresta();

    /**
     * @brief Retorna o identificador do vértice de origem.
     * @return ID do vértice de origem.
     */
    int getOrigem();

    /**
     * @brief Retorna o identificador do vértice de destino.
     * @return ID do vértice de destino.
     */
    int getDestino();

    /**
     * @brief Retorna o peso da aresta.
     * @return Peso da aresta.
     */
    float getPeso();

    /**
     * @brief Retorna o próximo nó de aresta na lista.
     * @return Ponteiro para o próximo NoAresta.
     */
    NoAresta* getProximo();

    /**
     * @brief Define o próximo nó de aresta na lista.
     * @param proximo Ponteiro para o novo próximo nó.
     */
    void setProximo(NoAresta* proximo);

    /**
     * @brief Define o identificador do vértice de origem.
     * @param novoId Novo identificador para o vértice de origem.
     */
    void setVerticeOrigem(int novoId);

    /**
     * @brief Define o identificador do vértice de destino.
     * @param novoId Novo identificador para o vértice de destino.
     */
    void setVerticeDestino(int novoId);
};

#endif // NO_ARESTA_H
