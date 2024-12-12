#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <cmath>
#include <string>

using namespace std;

class Grafo
{
private:
    //int numVertices;
    //bool direcionado;
public:
    Grafo();
    ~Grafo();
    bool eh_bipartido();
    int n_conexo();
    int get_grau();
    int get_ordem();
    bool eh_direcionado();
    bool vertice_ponderado();
    bool aresta_ponderada();
    bool eh_completo();
    bool eh_arvore();
    bool possui_articulacao();
    bool possui_ponte();
};

Grafo::Grafo()
{
    cout << "Teste rodando" << endl;
}

Grafo::~Grafo()
{
}
