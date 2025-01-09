#include <fstream>
#include <iostream>
#include <string>
#include "../../headers/GrafoMatriz.h"
#include "../../headers/GrafoLista.h"
#include "../../headers/Grafo.h"
#include "../../headers/Aresta.h"
#include "../../headers/Vertice.h"

using namespace std;

int main(int argc, char* argv[]) {

    string opcao1 = argv[1];
    string opcao2 = argv[2];
    string arquivoEntrada = argv[3];
    string arquivoSaida = (argc == 5) ? argv[4] : "";

    if (opcao1 == "-d" && opcao2 == "-m") {
        // Caso 1: Imprime descrição do grafo usando matriz de adjacência
        GrafoMatriz* grafo = GrafoMatriz::carrega_grafo(arquivoEntrada);
        if (grafo) {
            grafo->imprimeGrafoMatriz();
            delete grafo;
        } else {
            cerr << "Erro ao carregar o grafo." << endl;
        }
    } else if (opcao1 == "-d" && opcao2 == "-l") {
        // Caso 2: Imprime descrição do grafo usando lista encadeada
        GrafoLista* grafo = GrafoLista::carrega_grafo(arquivoEntrada);
        if (grafo) {
            grafo->imprimeGrafoLista();
            delete grafo;
        } else {
            cerr << "Erro ao carregar o grafo." << endl;
        }
    } else if (opcao1 == "-c" && opcao2 == "-m" && !arquivoSaida.empty()) {
        // Caso 3: Cria grafo aleatório com matriz de adjacência e salva no arquivo
        GrafoMatriz::novo_grafo(arquivoEntrada, arquivoSaida);
    } else if (opcao1 == "-c" && opcao2 == "-l" && !arquivoSaida.empty()) {
        // Caso 4: Cria grafo aleatório com lista encadeada e salva no arquivo
        GrafoLista::novo_grafo(arquivoEntrada, arquivoSaida);
    } else {
        return 1;
    }

    cout << "Programa finalizado!" << endl;
    return 0;
}