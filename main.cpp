#include "include/GrafoMatriz.h"
#include "include/GrafoLista.h"
#include "include/Grafo.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Para compilar: CTRL+SHIFT+B ou g++ -o main main.cpp src/Grafo.cpp src/GrafoMatriz.cpp src/GrafoLista.cpp src/ListaAdjAresta.cpp src/ListaAdjVertice.cpp src/NoAresta.cpp src/NoVertice.cpp
// Para executar: ./main

int main() {
    
    cout << "============================== LISTA ==============================" << endl;
    GrafoLista grafoLista(0, false, false, false);
    grafoLista.carrega_grafo(&grafoLista, "entradas/grafo.txt");
    grafoLista.imprimeGrafoLista();
    grafoLista.imprimeListaAdj();
    cout << "============================== FIM LISTA ==============================" << endl << endl;
    
    cout << "============================== MATRIZ ==============================" << endl;
    GrafoMatriz grafoMatriz(0, false, false, false);
    grafoMatriz.imprimirMatrizAdj();
    grafoMatriz.carrega_grafo(&grafoMatriz, "entradas/grafo.txt");
    grafoMatriz.imprimeGrafoMatriz();
    grafoMatriz.imprimirMatrizAdj();
    cout << endl << "Grafo finalizado!" << endl;
    cout << "============================== FIM MATRIZ ==============================" << endl << endl;

    return 0;
}