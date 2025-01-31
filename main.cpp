#include <fstream>
#include <iostream>
#include <string>
#include "include/GrafoMatriz.h"
#include "include/GrafoLista.h"
#include "include/Grafo.h"
#include "include/Aresta.h"
#include "include/Vertice.h"

using namespace std;
// Para compilar: CTRL+SHIFT+B ou g++ -o main main.cpp src/GrafoMatriz.cpp src/GrafoLista.cpp src/Grafo.cpp src/Aresta.cpp src/Vertice.cpp
// Para executar: ./main

int main() {
    GrafoLista grafo(10, false, false, false);
    grafo.carrega_grafo(&grafo,  "entradas/grafo.txt");
    grafo.imprime();
    grafo.getVertices()[0].getGrauVertice();
    return 0;
}