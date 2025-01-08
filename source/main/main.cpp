#include <fstream>
#include <iostream>
#include <string>

#include "../../headers/GrafoMatriz.h"
#include "../../headers/GrafoLista.h"
#include "../../headers/Grafo.h"
#include "../../headers/Aresta.h"
#include "../../headers/Vertice.h"

using namespace std;
//  Para compilar e executar o programa:
//  1 - Com qualquer arquivo do proejto aberto, tecle: CTRL + SHIFT + B
//  2 - Digite no termianl: cd source/main
//  3 - Digite no terminal: ./main.exe

//  OBS: no arquivo "grafo.txt" não use barra de comentarios, pois o programa não irá ler devidamente o arquivo

int main() {
   GrafoMatriz* grafo = GrafoMatriz::carrega_grafo("grafo.txt"); 
   grafo->imprimeGrafoMatriz();
   delete grafo;

   GrafoMatriz* grafo2 = GrafoMatriz::novo_grafo();
   delete grafo2;
   cout << "Programa finalizado!" << endl;
   return 0;
}