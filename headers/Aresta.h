#ifndef ARESTA_H
#define ARESTA_H

#include <iostream>

class Aresta {
private:
    int origem;
    int destino;
    int peso;

public:
    Aresta(); // Construtor padrão
    Aresta(int origem, int destino, int peso = 0); // Construtor parametrizado
    ~Aresta();

    int getOrigem();
    int getDestino();
    int getPeso(); 

    void setOrigem(int origem);
    void setDestino(int destino);
    void setPeso(int peso);
};

#endif
