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
    
    // cout << "============================== LISTA ==============================" << endl;
    // GrafoLista grafoLista(0, false, false, false);
    // grafoLista.carrega_grafo(&grafoLista, "entradas/grafo.txt");
    // grafoLista.imprimeGrafoLista();
    // grafoLista.imprimeListaAdj();

    // cout << "============================== TESTE 1 ==============================" << endl;
    // grafoLista.adicionar_novo_vertice(7, 0);
    // grafoLista.adicionar_aresta(7, 1, 1);
    // grafoLista.adicionar_aresta(7, 2, 1);
    // grafoLista.adicionar_aresta(3, 7, 1);
    // grafoLista.adicionar_aresta(4, 7, 1);
    // grafoLista.adicionar_aresta(5, 6, 1);
    // grafoLista.adicionar_aresta(8, 1, 1);
    // grafoLista.adicionar_aresta(1, 9, 1);
    // grafoLista.adicionar_aresta(10, 11, 1);
    // grafoLista.imprimeGrafoLista();
    // grafoLista.imprimeListaAdj();

    // cout << "============================== TESTE 2 ==============================" << endl;
    // grafoLista.remover_aresta(7, 1);
    // grafoLista.remover_aresta(2, 4);
    // grafoLista.remover_aresta(5, 6);
    // grafoLista.imprimeListaAdj();
    // grafoLista.imprimeGrafoLista();

    // cout << "============================== TESTE 3 ==============================" << endl;
    // grafoLista.remover_vertice(4);
    // grafoLista.remover_vertice(5);
    // grafoLista.remover_vertice(6);
    // grafoLista.imprimeListaAdj();
    // grafoLista.imprimeGrafoLista();
    // cout << "============================== FIM LISTA ==============================" << endl << endl;
    
    cout << "============================== MATRIZ ==============================" << endl;
    GrafoMatriz grafoMatriz(0, false, false, false);
    grafoMatriz.carrega_grafo(&grafoMatriz, "entradas/grafo.txt");
    grafoMatriz.imprimeGrafoMatriz();
    grafoMatriz.imprimirMatrizAdj();
    cout << endl << "Grafo finalizado!" << endl;
    cout << "============================== FIM MATRIZ ==============================" << endl << endl;

    return 0;
}