#include "../headers/Vertice.h"
#include <iostream>

using namespace std;

Vertice::Vertice(){
    nArestas = 0; //Valor Padrao
    id = 0; //Valor Padrao
    peso = 0; //Valor Padrao
    arestas = new Aresta[100]; //Valor Padrao
}

Vertice::Vertice(int id, int peso){
    this->id = id;
    this->peso = peso;
    arestas = new Aresta[100]; //Valor Padrao
}

Vertice::~Vertice() {
    delete[] arestas;
}

int Vertice::getId() {
    return id;
}

void Vertice::setId(int id) {
    this->id = id;
}

int Vertice::getPeso() {
    return peso;
}

void Vertice::setPeso(int peso) {
    this->peso = peso;
}

Aresta* Vertice::getArestas() {
    return arestas;
}

bool Vertice::existeAresta(int destino) {
    for (int i = 0; i < nArestas; ++i) {
        if (arestas[i].getDestino() == destino) return true;
    }
    return false;
}

int Vertice::getGrau() {
    return nArestas;
}