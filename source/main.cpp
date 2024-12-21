#include <iostream>
#include "../headers/GrafoMatriz.h"
#include "../headers/GrafoLista.h"
#include "../headers/Grafo.h"
#include "../headers/Aresta.h"
#include "../headers/Vertice.h"

using namespace std;
    // Para compilar e executar o programa, utilize os seguintes comandos:
    // cd source

    //  CADA VEZ QUE RODAR USE O COMANDO ABAIXO  PARA COMPILAR
    // g++ -Wall -Wextra -g3 main.cpp Grafo.cpp GrafoMatriz.cpp GrafoLista.cpp Vertice.cpp Aresta.cpp -o main.exe; .\main.exe
void imprime(Grafo* grafo) {
    cout << "grau: " << endl;
    cout << "Ordem: " << endl;
    cout << "Direcionado " << grafo->eh_direcionado() << endl;
    cout << "Componentes conexas " << endl;
    cout << "Vertices ponderados " << grafo->vertice_ponderado() << endl;
    cout << "Arestas ponderadas: " << grafo->aresta_ponderada() << endl;
    cout << "Completo: " << endl;
    cout << "Bipartido: " << endl;
    cout << "Arvore: " << endl;
    cout << "Aresta Ponte: " << endl;
    cout << "Vertice de Articulacao: " << endl;
}

int main() {

    GrafoMatriz grafoMatriz(3, true, true, true);
    grafoMatriz.getVertices()[0].setPeso(2);
    grafoMatriz.getVertices()[1].setPeso(3);
    grafoMatriz.getVertices()[2].setPeso(7);

    grafoMatriz.getVertices()[0].getArestas()[0].setDestino(1);
    grafoMatriz.getVertices()[0].getArestas()[0].setOrigem(2);
    grafoMatriz.getVertices()[0].getArestas()[0].setPeso(6);

    grafoMatriz.getVertices()[1].getArestas()[1].setDestino(2);
    grafoMatriz.getVertices()[1].getArestas()[1].setOrigem(1);
    grafoMatriz.getVertices()[1].getArestas()[1].setPeso(4);

    grafoMatriz.getVertices()[2].getArestas()[2].setDestino(2);
    grafoMatriz.getVertices()[2].getArestas()[2].setOrigem(3);
    grafoMatriz.getVertices()[2].getArestas()[2].setPeso(-5);

    cout << "Grafo Matriz" << endl;
    imprime(&grafoMatriz);
    cout << endl;
    
    GrafoLista grafoLista(3, true, true, true);
    grafoLista.getVertices()[0].setPeso(2);
    grafoLista.getVertices()[1].setPeso(3);
    grafoLista.getVertices()[2].setPeso(7);

    grafoLista.getVertices()[0].getArestas()[0].setDestino(1);
    grafoLista.getVertices()[0].getArestas()[0].setOrigem(2);
    grafoLista.getVertices()[0].getArestas()[0].setPeso(6);

    grafoLista.getVertices()[1].getArestas()[1].setDestino(2);
    grafoLista.getVertices()[1].getArestas()[1].setOrigem(1);
    grafoLista.getVertices()[1].getArestas()[1].setPeso(4);

    grafoLista.getVertices()[2].getArestas()[2].setDestino(2);
    grafoLista.getVertices()[2].getArestas()[2].setOrigem(3);
    grafoLista.getVertices()[2].getArestas()[2].setPeso(-5);

    cout << "Grafo Lista" << endl;
    imprime(&grafoLista);
    cout << "Fim" << endl;
   
    return 0;
}
