#ifndef NO_ARESTA_H
#define NO_ARESTA_H

class NoAresta {
private:
    int idVerticeOrigem;        // Identificador do vertice de origem
    int idVerticeDestino;       // Identificador do vertice de destino
    int peso;                   // Peso da aresta
    NoAresta* proximo;          // Ponteiro para o próximo nó aresta

public:
    NoAresta(int idVerticeOrigem, int idVerticeDestino, int peso); // Construtor
    ~NoAresta(); // Destrutor

    int getOrigem();
    int getDestino();
    int getPeso();                                          //Retorna o peso da aresta
    NoAresta* getProximo();                                 // Retorna o próximo nó aresta
    void setProximo(NoAresta* proximo);                     // Define o próximo nó aresta
};

#endif // NO_H