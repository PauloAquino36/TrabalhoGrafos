#include "include/GrafoMatriz.h"
#include "include/GrafoLista.h"
#include "include/Grafo.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Para compilar: CTRL+SHIFT+B ou g++ -o main main.cpp src/Grafo.cpp src/GrafoMatriz.cpp src/GrafoLista.cpp src/ListaAdjAresta.cpp src/ListaAdjVertice.cpp src/NoAresta.cpp src/NoVertice.cpp
// Para executar Matriz: ./main -d -m grafo.txt
// Para executar Lista:  ./main -d -l grafo.txt

int main(int argc, char* argv[]) {
    string modo = argv[2];
    string arquivo = "./entradas/" + string(argv[3]);

    if (modo == "-m") {
        cout << endl << "============================== MATRIZ ==============================" << endl << endl;
        GrafoMatriz grafoMatriz(0, false, false, false);
        grafoMatriz.carrega_grafo(&grafoMatriz, arquivo);
        grafoMatriz.imprimeGrafoMatriz();
        grafoMatriz.coberturaVerticesGulosa();
        cout << endl << "Quantidade de Arestas no grafo: " << grafoMatriz.get_num_arestas_grafo() << endl;
        cout << endl << "============================== FIM MATRIZ ==============================" << endl << endl;
    } else if (modo == "-l") {
        cout << endl << "============================== LISTA ==============================" << endl << endl;
        GrafoLista grafoLista(0, false, false, false);
        grafoLista.carrega_grafo(&grafoLista, arquivo);
        grafoLista.imprimeGrafoLista();
        grafoLista.alg_guloso_cobertura_vertice();
        grafoLista.alg_randomizado_cobertura_vertice();
        cout << "Quantidade de Arestas no grafo: " << grafoLista.get_num_arestas_grafo() << endl;
        cout << endl << "============================== FIM LISTA ==============================" << endl << endl;
    } else {
        cerr << "Use ./main -d -m grafo.txt  ou ./main -d -l grafo.txt" << endl;
        return 1;
    }

    return 0;
}