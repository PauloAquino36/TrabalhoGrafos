#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "Vertice.h"

class Grafo {
protected:
    Vertice* vertices; // Lista de vértices
    int nVertices;          // Número de vértices (ordem) do grafo
    int grau;               // Grau do grafo (número de arestas do vertice que possui mais arestas)
    bool direcionado;       // Indica se o grafo é direcionado
    bool ponderadoVertices; // Indica se o grafo possui peso nos vertices
    bool ponderadoArestas;  // Indica se o grafo possui peso nas arestas

public:
    //Construtor e Destrutor
    Grafo(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);
    ~Grafo();

    //Funcoes principais
    virtual bool eh_bipartido();       //Verifica se o grafo eh bipartido ou nao
    virtual int n_conexo();            //Retorna a quantidade total de componentes conexas do grafo
    virtual int get_grau();            //Retorna o grau do grafo
    virtual int get_ordem();           //Retorna a ordem do grafo (numero de vertices do grafo)
    virtual bool eh_direcionado();     //Retorna se o grafo eh direcionado ou nao
    virtual bool vertice_ponderado();  //Retorna se o grafo possui peso nos vertices ou nao
    virtual bool aresta_ponderada();   //Retorna se o grafo possui peso nas arestas ou nao
    virtual bool eh_completo();        //Verifica se o grafo eh completo ou nao
    virtual bool eh_arvore();          //Verifica se o grafo eh uma arvore ou nao
    virtual bool possui_articulacao(); //Verifica se o grafo possui pelo menos 1 vertice de articulacao
    virtual bool possui_ponte();       //Verifica se o grafo possui pelo menos 1 aresta ponte


    static Grafo* carrega_grafo(const std::string& nomeArquivo);        //Gera um grafo a partir do arquivo grafo.txt
    static void novo_grafo(const std::string& nomeArquivoEntrada, const std::string& nomeArquivoSaida);         //Gera um novo grafo a partir do arquivo descricao.txt

    void imprime();        //Imprime os atributos do grafo

};

#endif
