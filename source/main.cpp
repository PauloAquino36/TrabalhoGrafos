#include <iostream>
#include "../headers/GrafoMatriz.h"
#include "../headers/Grafo.h"

using namespace std;

int main() {
    // Para compilar e executar o programa, utilize os seguintes comandos:
    // g++ -Wall -Wextra -g3 main.cpp Grafo.cpp GrafoMatriz.cpp -o main.exe
    // .\main.exe

    
    GrafoMatriz grafo(5, true);

    //grafo.adicionar_aresta(0, 1, 1);
    //grafo.adicionar_aresta(1, 2, 1);
    //grafo.adicionar_aresta(2, 3, 1);
    //grafo.adicionar_aresta(0, 4, 1);

    //grafo.imprimir();  // Imprime a matriz de adjacência
    
   cout << "Teste rodando" << endl;
   
    return 0;
}
