#include "../include/ListaAdjVertice.h"
#include "../include/NoVertice.h"
#include <iostream>

using namespace std;

// #region Construtor e Destrutor
ListaAdjVertice::ListaAdjVertice() {
    this->cabeca = nullptr;
}

ListaAdjVertice::~ListaAdjVertice() {
    // Desaloca a memoria para cada no da lista de vertices
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        NoVertice* next = atual->getProximo();
        delete atual;
        atual = next;
    }
}
// #endregion

// Retorna o primeiro no da lista (primeiro vertice do grafo)
NoVertice* ListaAdjVertice::getCabeca() {
    return this->cabeca;
}

// Retorna a quantidade de vertices na lista / quantidade total de vertices no grafo
int ListaAdjVertice::getNumVertices() {
    int tamanho = 0;
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        tamanho++;
        atual = atual->getProximo();
    }
    return tamanho;
}

// Retorna o vertice[id] da lista
NoVertice* ListaAdjVertice::getVertice(int id) {
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getIdVertice() == id) {
            return atual;
        }
        atual = atual->getProximo();
    }
    return nullptr;
}

// Adiciona um vertice a lista
void ListaAdjVertice::adicionar_vertice(int id, float peso) {
    NoVertice* novoNo = new NoVertice(id, peso);
    novoNo->setProximo(this->cabeca);
    this->cabeca = novoNo;

    //cout << "Adicionado Vertice " << novoNo->getIdVertice() << endl;                    /* { DEBUG } */
}

// Adiciona uma aresta ao vertice
void ListaAdjVertice::adicionar_aresta(int origem, int destino, float peso) {
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getIdVertice() == origem) {
            atual->adicionar_aresta(destino, peso);
        }
        atual = atual->getProximo();
    }
}

// Remove uma aresta do vertice
void ListaAdjVertice::remover_aresta(int origem, int destino) {
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getIdVertice() == origem) {
            atual->remover_aresta(destino);
        }
        atual = atual->getProximo();
    }
}

// Remove a primeira aresta do vertice
void ListaAdjVertice::remover_primeira_aresta(int id) {
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getIdVertice() == id) {
            atual->remover_primeira_aresta();
        }
        atual = atual->getProximo();
    }
}

// Remove um vertice da lista
void ListaAdjVertice::remover_vertice(int id) {
    NoVertice* atual = this->cabeca;
    NoVertice* anterior = nullptr;
    NoVertice* remover =  nullptr;
    while (atual != nullptr) {
        if (atual->getIdVertice() == id) {
            if (anterior == nullptr) {
                this->cabeca = atual->getProximo();
            } else {
                anterior->setProximo(atual->getProximo());
            }
            remover = atual;
        }
        // Remove as arestas que apontam para o vertice a ser removido
        atual->remover_aresta(id);
        // Atualiza os ponteiros
        anterior = atual;
        atual = atual->getProximo();
    }
    // Remove o vertice
    //cout << "Removendo vertice " << remover->getIdVertice() << endl;            /* { DEBUG } */
    delete remover;
    
    // Recalculando ID dos vertices
    atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getIdVertice() > id) {
            atual->setIdVertice(atual->getIdVertice() - 1);
        }
        atual = atual->getProximo();
    }

    // Reorganizando as arestas
    atual = this->cabeca;
    while (atual != nullptr) {
        NoAresta* arestaAtual = atual->getArestas()->getCabeca();
        while (arestaAtual != nullptr) {
            if (arestaAtual->getDestino() > id) {
                arestaAtual->setVerticeDestino(arestaAtual->getDestino() - 1);
            }
            arestaAtual = arestaAtual->getProximo();
        }
        atual = atual->getProximo();
    }

}

// Imprime a lista de adjacencia
void ListaAdjVertice::imprimir() {
    // Imprime a lista de adjacencia
    cout << "__________________________________________________________________" << endl;
    cout << endl << "--- Lista de Adjacencia ---" << endl << endl ;
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        cout << "Vertice " << atual->getIdVertice() << " -> ";
        NoAresta* atualAresta = atual->getArestas()->getCabeca();
        while (atualAresta != nullptr) {
            cout << atualAresta->getDestino() << "(" << atualAresta->getPeso() << ")"<< "  ";
            atualAresta = atualAresta->getProximo();
        }
        cout << endl;
        atual = atual->getProximo();
    }
    cout << "__________________________________________________________________" << endl << endl;
}