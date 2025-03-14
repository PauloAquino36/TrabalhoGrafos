#include "include/GrafoMatriz.h"
#include "include/GrafoLista.h"
#include "include/Grafo.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Para compilar ------------------------------------------ g++ -o main main.cpp src/*.cpp
// Para executar Descricao do Grafo Matriz ---------------- ./main -d -m grafo.txt
// Para executar Descricao do Grafo Lista ----------------- ./main -d -l grafo.txt
// Para executar Algoritmos Gulosos do Grafo Matriz ------- ./main -p -m grafo.txt
// Para executar Descricao do Grafo Lista ----------------- ./main -p -l grafo.txt

//////Extra
// Para executar Analise de Algoritmos Matriz --------------------- ./main -a -m grafo.txt
// Para executar Analise de Algoritmos Lista--------------------- ./main -a -l grafo.txt

void comando_invalido(){
    cerr << endl << "Comando invalido. Use: " << endl;
    cerr << "$ ./main -d -m grafo.txt: Para imprimir a descricao do Grafo Matriz" << endl;
    cerr << "$ ./main -d -l grafo.txt: Para imprimir a descricao do Grafo Lista" << endl;
    cerr << "$ ./main -p -m grafo.txt: Para imprimir a solucao de cobertura de vertices do Grafo Matriz" << endl;
    cerr << "$ ./main -p -l grafo.txt: Para imprimir a solucao de cobertura de vertices do Grafo Lista" << endl <<endl;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        comando_invalido();
        return 1;
    }
    string modo = argv[2];
    string arquivo = "./entradas/" + string(argv[3]);

    if (modo == "-m") {
        cout << endl << "============================== MATRIZ ==============================" << endl << endl;
        GrafoMatriz grafoMatriz(0, false, false, false);
        grafoMatriz.carrega_grafo(&grafoMatriz, arquivo);

        if (string(argv[1]) == "-d") {
            grafoMatriz.imprimir_descricao();
        } else if (string(argv[1]) == "-p") {
            grafoMatriz.imprimir_algoritmos_cobertura_vertice(&grafoMatriz);
        } else if(string(argv[1]) == "-a"){
            grafoMatriz.analise_algoritmos_cobertura_vertice(&grafoMatriz, 100);
        }
        else{
            comando_invalido();
            return 1;
        }
        cout << endl << "============================== FIM MATRIZ ==============================" << endl << endl;
    } else if (modo == "-l") {
        cout << endl << "============================== LISTA ==============================" << endl << endl;
        GrafoLista grafoLista(0, false, false, false);
        grafoLista.carrega_grafo(&grafoLista, arquivo);

        if (string(argv[1]) == "-d") {
            grafoLista.imprimir_descricao();
        } else if (string(argv[1]) == "-p") {
            grafoLista.imprimir_algoritmos_cobertura_vertice(&grafoLista);
        } else{
            comando_invalido();
            return 1;
        }
        cout << endl <<  "============================== FIM LISTA ==============================" << endl << endl;
    } else {
        comando_invalido();
        return 1;
    }
    return 0;
}