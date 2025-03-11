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
        //cout << "Excluindo Noh 1..." << endl;
        //grafoMatriz.remover_vertice(1);
        //cout << "Excluindo primeira aresta do Noh 2..." << endl;
        //grafoMatriz.remover_primeira_aresta(2);
        grafoMatriz.imprimeGrafoMatriz();
        //grafoMatriz.calcula_maior_menor_dist();
        cout << "Quantidade de Arestas no grafo: " << grafoMatriz.get_num_arestas_grafo() << endl;
        grafoMatriz.coberturaVerticesGulosa();
        cout << endl << "============================== FIM MATRIZ ==============================" << endl << endl;
    } else if (modo == "-l") {
        cout << endl << "============================== LISTA ==============================" << endl << endl;
        GrafoLista grafoLista(0, false, false, false);
        grafoLista.carrega_grafo(&grafoLista, arquivo);
        //cout << "Excluindo Noh 1..." << endl;
        //grafoLista.remover_vertice(1);
        //cout << "Excluindo primeira aresta do Noh 2..." << endl ;
        //grafoLista.remover_primeira_aresta(2);
        grafoLista.imprimeGrafoLista();
        //grafoLista.calcula_maior_menor_dist();
        //cout << "Quantidade de Arestas no grafo: " << grafoLista.get_num_arestas_grafo() << endl;
        grafoLista.alg_guloso_cobertura_vertice();
        cout << endl << "============================== FIM LISTA ==============================" << endl << endl;
    } else {
        cerr << "Use ./main -d -m grafo.txt  ou ./main -d -l grafo.txt" << endl;
        return 1;
    }

    return 0;
}