#include <iostream>
#include "../headers/GrafoMatriz.h"
#include "../headers/Grafo.h"

using namespace std;
    // Para compilar e executar o programa, utilize os seguintes comandos:
    // cd source
    // g++ -Wall -Wextra -g3 main.cpp Grafo.cpp GrafoMatriz.cpp -o main.exe; .\main.exe
int main() {
    GrafoMatriz *g = new GrafoMatriz(5, false);
    g->adicionar_aresta(0, 1, 1);
    g->imprimir();
   cout << "Finalizado" << endl;
   
    return 0;
}
