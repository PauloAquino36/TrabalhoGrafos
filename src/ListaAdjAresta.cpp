#include "../include/ListaAdjAresta.h"
#include "../include/NoAresta.h"
#include "../include/GrafoLista.h"
#include <iostream>

using namespace std;

// #region Construtor e Destrutor
ListaAdjAresta::ListaAdjAresta(GrafoLista* grafo) {
    this->grafo = grafo;
    this->cabeca = nullptr;
}

ListaAdjAresta::~ListaAdjAresta() {
    // Desaloca a memoria para cada no da lista de arestas
    NoAresta* atual = this->cabeca;
    while (atual != nullptr) {
        NoAresta* next = atual->getProximo();
        delete atual;
        atual = next;
    }
}
// #endregion

// #region Funcoes auxiliares
// Retorna o primeiro no da lista (primeira aresta do vertice)
NoAresta* ListaAdjAresta::getCabeca() {
    return this->cabeca;
}

// Adiciona uma aresta a lista
void ListaAdjAresta::adicionar_aresta(int origem, int destino, float peso) {
    // Verifica se a aresta ja existe
    NoAresta* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getOrigem() == origem && atual->getDestino() == destino) {
            //cout << "Erro: Aresta " << origem << " -> " << destino << " ja existe. Nao eh possivel multiarestas" <<  endl;                       /* { DEBUG } */
            return;
        }
        atual = atual->getProximo();
    }

    // Adiciona uma nova aresta
    NoAresta* novaAresta = new NoAresta(origem, destino, peso, grafo->getNumArestasGrafo()+1);
    grafo->incrementaNumArestasGrafo();
    novaAresta->setProximo(this->cabeca);
    this->cabeca = novaAresta;
    //cout << "Adicionada Aresta " << novaAresta->getOrigem() << " -> " << novaAresta->getDestino() << endl;          /* { DEBUG } */
}

// Remove uma aresta da lista
void ListaAdjAresta::remover_aresta(int origem, int destino) {
    NoAresta* atual = this->cabeca;
    NoAresta* anterior = nullptr;
    while (atual != nullptr) {
        if (atual->getOrigem() == origem && atual->getDestino() == destino) {
            if (anterior == nullptr) {
                this->cabeca = atual->getProximo();
            } else {
                anterior->setProximo(atual->getProximo());
            }
            delete atual;
            grafo->decrementaNumArestasGrafo();
            //cout << "Removida Aresta " << origem << " -> " << destino << endl;                                      /* { DEBUG } */
            return;
        }
        anterior = atual;
        atual = atual->getProximo();
    }

    //cout << "Erro: Aresta " << origem << " -> " << destino << " nao existe." <<  endl;                              /* { DEBUG } */
}

// Remove a primeira aresta da lista
void ListaAdjAresta::remover_primeira_aresta() {
    if (this->cabeca == nullptr) {
        cout << "Vertice nao possui arestas" << endl;
        return;
    }

    NoAresta* atual = this->cabeca;
    NoAresta* menor = this->cabeca;

    while (atual != nullptr) {
        if (atual->getDestino() < menor->getDestino()) {
            menor = atual;
        }
        atual = atual->getProximo();
    }
    remover_aresta(menor->getOrigem(), menor->getDestino());
}

// Retorna o tamanho da lista / numero de vertices vizinhos / grau do vertice
int ListaAdjAresta::getNumVerticesVizinhos() {
    int tamanho = 0;
    NoAresta* atual = this->cabeca;
    while (atual != nullptr) {
        tamanho++;
        atual = atual->getProximo();
    }
    return tamanho;
}

int ListaAdjAresta::getIdAresta(int destino) {
    NoAresta* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getDestino() == destino) {
            return atual->getIdAresta();
        }
        atual = atual->getProximo();
    }
    return -1;
}