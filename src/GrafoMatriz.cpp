#include "../include/GrafoMatriz.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//Contrutor e Destrutor
GrafoMatriz::GrafoMatriz(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas) : Grafo(numVertices, direcionado, ponderadoVertices, ponderadoArestas)
{
    if (numVertices <= 0)
    {
        numVertices = 1;
    }
    matrizAdj = new int *[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        matrizAdj[i] = new int[numVertices];
        for (int j = 0; j < numVertices; j++)
        {
            matrizAdj[i][j] = 0; // Inicializa com 0 (sem aresta)
        }
    }
}

GrafoMatriz::~GrafoMatriz() {
    if (matrizAdj != nullptr) {  // Verifica se há memória alocada
        for (int i = 0; i < numVertices; i++) {
            delete[] matrizAdj[i];
        }
        delete[] matrizAdj;
        matrizAdj = nullptr; // Evita ponteiro danificado
    }
}

//Funcoes auxiliares

void GrafoMatriz::atualiza_grafo(int numVertices) {
    // Verifica se a matrizAdj já foi alocada antes de liberar a memória
    if (matrizAdj != nullptr) {
        for (int i = 0; i < this->numVertices; i++) {
            delete[] matrizAdj[i]; // Libera cada linha da matriz
        }
        delete[] matrizAdj; // Libera o array de ponteiros
        matrizAdj = nullptr; // Evita ponteiro danificado
    }

    this->numVertices = numVertices;

    // Aloca uma nova matriz de adjacência com o novo tamanho
    matrizAdj = new int*[numVertices];
    for (int i = 0; i < numVertices; i++) {
        matrizAdj[i] = new int[numVertices](); // Inicializa automaticamente com 0
    }
}
void GrafoMatriz::adicionar_aresta(int origem, int destino, int peso)
{
    //cout << "Num Vertices:" << numVertices << endl;
    //cout << "Origem: " << origem << " / Destino: " << destino << " / Num Vertices:" << numVertices << endl;
    
     if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices)
     {
         cout << "Erro: indices de origem ou destino invalidos.\n";
         return;
     }
     
    //cout << "conluido: " <<  "Origem: " << origem << " / Destino: " << destino << endl;

     if(direcionado){
        matrizAdj[origem][destino] = peso;
     }
     else{
        matrizAdj[origem][destino] = 1;
        matrizAdj[destino][origem] = 1;
     }
}
int GrafoMatriz::get_num_vizinhos(int id) {
    if (id < 0 || id >= numVertices) {
        return 0; // Retorna 0 se o ID do vértice for inválido
    }

    int contador = 0;
    for (int i = 0; i < numVertices; i++) {
        if (matrizAdj[id][i] != 0) { // Se houver uma aresta entre os vértices
            contador++;
                if(!direcionado){
                    contador++;
            }
        }
    }
    return contador;
}
void GrafoMatriz::dfs(int id, bool* visitado) {
    if (id < 0 || id >= numVertices || visitado[id]) {
        return; // Verifica se o vértice é válido ou já foi visitado
    }

    visitado[id] = true; // Marca o vértice como visitado

    for (int i = 0; i < numVertices; i++) {
        if (matrizAdj[id][i] != 0 && !visitado[i]) { // Se houver uma aresta e o vértice não foi visitado
            dfs(i, visitado);
        }
    }
}


//Funcoes de imprimir
void GrafoMatriz::imprimirMatrizAdj()
{
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            std::cout << matrizAdj[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void GrafoMatriz::imprimeGrafoMatriz()
{
    cout << "__________________________________________________________________" << endl;
    cout << endl
         << "--- Grafo Matriz ---" << endl;
    cout << "__________________________________________________________________" << endl
         << endl;
    imprime();
}
