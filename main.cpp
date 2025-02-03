#include "include/GrafoMatriz.h"
#include "include/GrafoLista.h"
#include "include/Grafo.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Para compilar: CTRL+SHIFT+B ou g++ -o main main.cpp src/GrafoMatriz.cpp src/GrafoLista.cpp src/Grafo.cpp src/NoAresta.cpp src/NoVertice.cpp
// Para executar: ./main

int main() {
    /*
    GrafoLista grafo(0, false, false, false);
    grafo.carrega_grafo(&grafo, "entradas/grafo.txt");
    grafo.imprimeGrafoLista();
    grafo.imprimeListaAdj();
    grafo.get_vizinhos(2);
    */

    GrafoMatriz grafo(0, false, false, false);
    grafo.imprimirMatrizAdj();
    grafo.carrega_grafo(&grafo, "entradas/grafo.txt");
    grafo.imprimirMatrizAdj();
    cout << endl << "Grafo finalizado!" << endl;
    
    return 0;
}