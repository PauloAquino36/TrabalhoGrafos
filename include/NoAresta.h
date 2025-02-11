#ifndef NO_ARESTA_H
#define NO_ARESTA_H

class NoAresta {
private:
    int idVerticeOrigem;                    // Identificador do vertice de origem
    int idVerticeDestino;                   // Identificador do vertice de destino
    int peso;                               // Peso da aresta
    NoAresta* proximo;                      // Ponteiro para o proximo no aresta

public:
    // Construtor e Destrutor
    NoAresta(int idVerticeOrigem, int idVerticeDestino, int peso);
    ~NoAresta();

    // Getters e Setters
    int getOrigem();                        // Retorna o vertice de origem
    int getDestino();                       // Retorna o vertice de destino
    int getPeso();                          //Retorna o peso da aresta
    NoAresta* getProximo();                 // Retorna o proximo no aresta
    void setProximo(NoAresta* proximo);     // Define o proximo no aresta
    void setVerticeOrigem(int novoId);      // Define o identificador do vertice de origem
    void setVerticeDestino(int novoId);     // Define o identificador do vertice de destino
};

#endif // NO_H