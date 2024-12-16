#include <iostream>
#include "../headers/GrafoMatriz.h"
#include "../headers/GrafoLista.h"
#include "../headers/Grafo.h"
#include "../headers/Aresta.h"

using namespace std;
    // Para compilar e executar o programa, utilize os seguintes comandos:
    // cd source
    // g++ -Wall -Wextra -g3 main.cpp Grafo.cpp GrafoMatriz.cpp GrafoLista.cpp Aresta.cpp -o main.exe; .\main.exe
int main() {
    cout << "Grafo Matriz" << endl;
    GrafoMatriz *g = new GrafoMatriz(5, false);
    g->adicionarAresta(0, 1, 1);
    g->imprimir();
    cout << endl;

    cout << "Grafo Lista" << endl;
    GrafoLista *l = new GrafoLista(5, false);
    l->adicionarAresta(0, 1, 1);
    l->imprimir();
    cout << endl;
    
   cout << "Finalizado" << endl;
   
    return 0;
}
