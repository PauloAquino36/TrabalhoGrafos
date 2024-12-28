#include <fstream>
#include <iostream>
#include <string>

#include "../headers/GrafoMatriz.h"
#include "../headers/GrafoLista.h"
#include "../headers/Grafo.h"
#include "../headers/Aresta.h"
#include "../headers/Vertice.h"

using namespace std;
// Para compilar e executar o programa, utilize os seguintes comandos:
// cd source
// CADA VEZ QUE RODAR USE O COMANDO ABAIXO  PARA COMPILAR
// g++ -Wall -Wextra -g3 main.cpp Grafo.cpp GrafoMatriz.cpp GrafoLista.cpp Vertice.cpp Aresta.cpp -o main.exe; .\main.exe

void imprime(Grafo *grafo, string tipo)
{
    cout << "__________________________________________________________________" << endl;
    cout << endl << "Grafo Impresso Tipo: " << (tipo == "m" ? "Matriz" : "Lista Encadeada") << endl;
    cout << "__________________________________________________________________" << endl << endl;
    cout << "grau: " << endl;
    cout << "Ordem: " << grafo->getNVertices() << endl;
    cout << "Direcionado " << grafo->eh_direcionado() << endl;
    cout << "Componentes conexas " << endl;
    cout << "Vertices ponderados " << grafo->vertice_ponderado() << endl;
    cout << "Arestas ponderadas: " << grafo->aresta_ponderada() << endl;
    cout << "Completo: " << endl;
    cout << "Bipartido: " << (grafo->eh_bipartido() ? "Sim" : "Nao") << endl;
    cout << "Arvore: " << endl;
    cout << "Aresta Ponte: " << endl;
    cout << "Vertice de Articulacao: " << endl;
    cout << "__________________________________________________________________" << endl << endl;
}

void carrega_grafo(string nomeArquivo, int vet[], int tamanhoVet, Grafo &grafo, string tipo)
{

    string filename = nomeArquivo;
    ifstream arquivo(filename);

    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo: " << filename << endl;
        return;
    }

    cout << "Conteudo do arquivo '" << filename << "':" << endl;

    string linha;
    int valor;
    int index = 0;

    while (getline(arquivo, linha) && index < tamanhoVet)
    {
        sscanf(linha.c_str(), "%d", &valor);
        // cout << valor << endl; // Apaga essa linha depois, Printa o valor lido para debug
        vet[index++] = valor; // Adiciona o valor ao array e incrementa o índice
    }

    if(tipo == "m"){
        grafo = GrafoMatriz(vet[1], vet[2], vet[4], vet[5]);
    } else if(tipo == "l"){
        grafo = GrafoLista(vet[1], vet[2], vet[4], vet[5]);
    } else {
        cerr << "Tipo de grafo inválido" << endl;
        return;
    }

    arquivo.close();
}

void novo_grafo(string nomeArquivo, string nomeArquivoSaida, int vet[], int tamanho, Grafo &grafo, string tipo)
{

    carrega_grafo(nomeArquivoSaida, vet, tamanho, grafo, tipo);
    ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo para escrita: " << nomeArquivo << endl;
        return;
    }

    cout << "Escrevendo no arquivo '" << nomeArquivo << "':" << endl;

    arquivo << grafo.getNVertices() << " " << grafo.eh_direcionado() << " " << grafo.vertice_ponderado() << " " << grafo.aresta_ponderada() << "    // numero de nos, direcionado, ponderado vertices, ponderado arestas" << endl;

    arquivo.close();
    cout << "Escrita concluida!" << endl;
}

int main() {
    const int tamanho = 10;
    int vet[tamanho] = {0}; // Array inicializado com zeros

    string tipo = "m"; //Trocar para "l" para grafo de lista e "m" para grafo de matriz

    Grafo grafo(0, false, false, false); // Inicialização com valores default
    
    ////codigo -d
    carrega_grafo("descricao.txt", vet, tamanho, grafo, tipo);
    imprime(&grafo, tipo);

    cout << "--------------------------------------------------------" << endl;

    ////codigo -c
    novo_grafo("grafo.txt", "descricao.txt", vet, tamanho, grafo, tipo);

    cout << "--------------------------------------------------------" << endl;
    cout << endl << "Fim" << endl;
   
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