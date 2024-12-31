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

void imprime(Grafo *grafo, string tipo)
{
   cout << "__________________________________________________________________" << endl;
   cout << endl << "Grafo Impresso Tipo: " << (tipo == "m" ? "Matriz" : "Lista Encadeada") << endl;
   cout << "__________________________________________________________________" << endl << endl;
   cout << "Grau: " << grafo->get_grau() << endl;
   cout << "Ordem: " << grafo->get_ordem() << endl;
   cout << "Direcionado: " << (grafo->eh_direcionado() ? "Sim" : "Nao") << endl;
   cout << "Componentes conexas: " << grafo->n_conexo() << endl;
   cout << "Vertices ponderados: " << (grafo->vertice_ponderado() ? "Sim" : "Nao") << endl;
   cout << "Arestas ponderadas: " << (grafo->aresta_ponderada() ? "Sim" : "Nao") << endl;
   cout << "Completo: " << (grafo->eh_completo() ? "Sim" : "Nao") << endl;
   cout << "Bipartido: " << (grafo->eh_bipartido() ? "Sim" : "Nao") << endl;
   cout << "Arvore: "<< (grafo->eh_arvore() ? "Sim" : "Nao") << endl;
   cout << "Aresta Ponte:  Nao esta Feita!" << endl;
   cout << "Vertice de Articulacao:  Nao esta Feita!" << endl;
   cout << "__________________________________________________________________" << endl << endl;
}

int main() {
   cout << "--------------------------------------------------------" << endl;
   //Grafo::novo_grafo("descricao.txt", "grafo.txt");
   Grafo* grafo = Grafo::carrega_grafo("grafo.txt");

   imprime(grafo, "m");
   
   cout << "--------------------------------------------------------" << endl;

   delete grafo;
   return 0;
}

//Como a main deve ficar na parte final
/*
int main(int argc, char *argv[])
{
    const int tamanho = 10;
    int vet[tamanho] = {0};              // Array inicializado com zeros
    Grafo grafo(0, false, false, false); // Inicialização com valores default

    // Verificar se os argumentos são suficientes
    if (argc < 4)
    {
        cerr << "Uso incorreto. Exemplos de uso:" << endl;
        cerr << "  main.out -d -m grafo.txt" << endl;
        cerr << "  main.out -d -l grafo.txt" << endl;
        cerr << "  main.out -c -m descricao.txt grafo.txt" << endl;
        cerr << "  main.out -c -l descricao.txt grafo.txt" << endl;
        return 1;
    }

    string modo = argv[1]; // -d ou -c
    string tipo = argv[2]; // -m ou -l

    if (modo == "-d")
    {
        if (tipo == "-m")
        {
            carrega_grafo("descricao.txt", vet, tamanho, grafo, "m");
            imprime(&grafo);
        }
        else if (tipo == "-l")
        {
            carrega_grafo("descricao.txt", vet, tamanho, grafo, "l");
            imprime(&grafo);
        }
    }
    else if (modo == "-c")
    {
        if (tipo == "-m")
        {
            novo_grafo("grafo.txt", "descricao.txt", vet, tamanho, grafo, "m");
        }
        else if (tipo == "-l")
        {
            novo_grafo("grafo.txt", "descricao.txt", vet, tamanho, grafo, "l"); // Modifique se necessário para arquivos de lista
        }
    }
    else
    {
        cerr << "Modo inválido. Use -d ou -c." << endl;
        return 1;
    }

    cout << "--------------------------------------------------------" << endl;
    cout << endl
         << "Fim" << endl;

    return 0;
}
*/

/*
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
    */