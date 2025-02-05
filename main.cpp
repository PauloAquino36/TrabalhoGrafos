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

    cout << "Iniciando o programa..." << endl;
    
    GrafoLista grafo(0, false, false, false);
    grafo.carrega_grafo(&grafo, "entradas/grafo.txt");
    grafo.imprimeGrafoLista();
    //grafo.imprimeListaAdj();
    //grafo.get_vizinhos(2);
    
    GrafoMatriz grafoM(0, false, false, false);
    grafoM.carrega_grafo(&grafoM, "entradas/grafo.txt");
    grafoM.imprimeGrafoMatriz();
    //grafoM.imprimirMatrizAdj();
    cout << endl << "Finalizado!" << endl;
    
    return 0;
}