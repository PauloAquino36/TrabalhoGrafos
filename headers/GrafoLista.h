#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "Grafo.h"
#include "Vertice.h"
class GrafoLista : public Grafo {
protected:
    Vertice* vertices;      // Lista de vertices
public:
    //Construtor e Destrutor
    GrafoLista(int nVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);
    ~GrafoLista();

    //Funcoes principais
    bool eh_bipartido() override;
    int n_conexo() override;
    int get_grau() override;
    int get_ordem() override;
    bool eh_direcionado() override;
    bool vertice_ponderado() override;
    bool aresta_ponderada() override;
    bool eh_completo() override;
    bool eh_arvore() override;
    bool possui_articulacao() override;
    bool possui_ponte() override;

    //Funcoes gera grafo
    static GrafoLista* carrega_grafo(const std::string& nomeArquivo);       //Cria um grafo em memoria de acordo com o arquivo grafo.txt
    static void novo_grafo(const std::string& nomeArquivoEntrada, const std::string& nomeArquivoSaida);    //Gera um novo grafo aleatorio de acordo com as informacoes do arquivo descricao.txt
    void geraGrafoAleatorio(int grau, int nVertices, bool direcionado, int compConexas, bool ponderadoVertices, bool ponderadoArestas, bool completo, bool bipartido, bool arvore, bool arestaPonte, bool verticeArticulacao);      //Funcao auxiliar para gerar o grafo aleatorio

    //Funcoes auxiliares
    Vertice* getVertices();             //Retorna o vetor de vertices do grafo
    void adicionarAresta(int origem, int destino, int peso);    //Adiciona uma aresta no grafo
    bool ehConexo();                    //Verifica se o grafo eh conexo ou nao
    void DFS(int v, bool visitado[]);   //Percorre o grafo em profundidade
    void DFS_Ponte(int v, bool visited[], int discovery[], int low[], int parent[], bool& ponteEncontrada);     //Funcao auxiliar para a funcao possui_ponte
    void DFSArticulacao(int v, bool visited[], int low[], int parent[], bool &articulacao);                     //Funcao auxiliar para a funcao possui_articulacao
    bool temCicloDFS(int v, bool visitado[], int pai);      //Verifica se o grafo possui ciclo
    void imprimeGrafoLista();
};

#endif // GRAFOLISTA_H