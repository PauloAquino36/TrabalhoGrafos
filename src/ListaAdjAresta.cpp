#include "../include/ListaAdjAresta.h"
#include "../include/NoAresta.h"
#include <iostream>

using namespace std;

ListaAdjAresta::ListaAdjAresta() {
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

NoAresta* ListaAdjAresta::getCabeca() {
    // Retorna o primeiro no da lista
    return this->cabeca;
}

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
    NoAresta* novaAresta = new NoAresta(origem, destino, peso);
    novaAresta->setProximo(this->cabeca);
    this->cabeca = novaAresta;
    //cout << "Adicionada Aresta " << novaAresta->getOrigem() << " -> " << novaAresta->getDestino() << endl;          /* { DEBUG } */
}

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
            //cout << "Removida Aresta " << origem << " -> " << destino << endl;                                      /* { DEBUG } */
            return;
        }
        anterior = atual;
        atual = atual->getProximo();
    }
    //cout << "Erro: Aresta " << origem << " -> " << destino << " nao existe." <<  endl;                              /* { DEBUG } */
}

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

int ListaAdjAresta::getNumVerticesVizinhos() {
    // Retorna o tamanho da lista / numero de vertices vizinhos / grau do vertice
    int tamanho = 0;
    NoAresta* atual = this->cabeca;
    while (atual != nullptr) {
        tamanho++;
        atual = atual->getProximo();
    }
    return tamanho;
}