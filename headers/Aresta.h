#ifndef ARESTA_H
#define ARESTA_H

#include <iostream>

class Aresta {
private:
    int destino;
    int peso;

public:
    Aresta(); // Construtor padrão
    Aresta(int destino, int peso = 0); // Construtor parametrizado
    ~Aresta();

    int getDestino() const;
    int getPeso() const; 

    void setDestino(int destino);
    void setPeso(int peso);
};

#endif
