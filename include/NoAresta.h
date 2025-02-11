#ifndef NO_ARESTA_H
#define NO_ARESTA_H

/**
 * @class NoAresta
 * @brief Classe que representa um nó de aresta em uma lista de adjacência.
 */
class NoAresta {
private:
    int idVerticeOrigem;                    ///< Identificador do vertice de origem
    int idVerticeDestino;                   ///< Identificador do vertice de destino
    float peso;                             ///< Peso da aresta
    NoAresta* proximo;                      ///< Ponteiro para o proximo no aresta

public:
    /**
     * @brief Construtor da classe NoAresta.
     * @param idVerticeOrigem Identificador do vertice de origem.
     * @param idVerticeDestino Identificador do vertice de destino.
     * @param peso Peso da aresta.
     */
    NoAresta(int idVerticeOrigem, int idVerticeDestino, float peso);

    /**
     * @brief Destrutor da classe NoAresta.
     */
    ~NoAresta();

    /**
     * @brief Retorna o vertice de origem.
     * @return Identificador do vertice de origem.
     */
    int getOrigem();

    /**
     * @brief Retorna o vertice de destino.
     * @return Identificador do vertice de destino.
     */
    int getDestino();

    /**
     * @brief Retorna o peso da aresta.
     * @return Peso da aresta.
     */
    float getPeso();

    /**
     * @brief Retorna o proximo no aresta.
     * @return Ponteiro para o proximo no aresta.
     */
    NoAresta* getProximo();

    /**
     * @brief Define o proximo no aresta.
     * @param proximo Ponteiro para o proximo no aresta.
     */
    void setProximo(NoAresta* proximo);

    /**
     * @brief Define o identificador do vertice de origem.
     * @param novoId Novo identificador do vertice de origem.
     */
    void setVerticeOrigem(int novoId);

    /**
     * @brief Define o identificador do vertice de destino.
     * @param novoId Novo identificador do vertice de destino.
     */
    void setVerticeDestino(int novoId);
};

#endif // NO_ARESTA_H