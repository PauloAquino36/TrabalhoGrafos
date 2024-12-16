#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <cmath>
#include <string>
#include "../headers/Grafo.h"

using namespace std;

Grafo::Grafo()
{
    this->numVertices = numVertices;
    this->direcionado = direcionado;
    cout << "Teste rodando" << endl;
}

Grafo::~Grafo()
{
    
}

bool Grafo::eh_direcionado()
{
    return direcionado;
}
int Grafo::get_numVertices()
{
    return numVertices;
}