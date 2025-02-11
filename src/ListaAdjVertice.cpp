#include "../include/ListaAdjVertice.h"
#include "../include/NoVertice.h"
#include <iostream>

using namespace std;

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

NoVertice* ListaAdjVertice::getCabeca() {
    // Retorna o primeiro no da lista
    return this->cabeca;
}

int ListaAdjVertice::getNumVertices() {
    // Retorna a quantidade de vertices na lista
    int tamanho = 0;
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        tamanho++;
        atual = atual->getProximo();
    }
    return tamanho;
}

NoVertice* ListaAdjVertice::getVertice(int id) {
    // Retorna o vertice[id] da lista
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getIdVertice() == id) {
            return atual;
        }
        atual = atual->getProximo();
    }
    return nullptr;
}

void ListaAdjVertice::adicionar_vertice(int id, float peso) {
    // Adiciona um novo vertice
    NoVertice* novoNo = new NoVertice(id, peso);
    novoNo->setProximo(this->cabeca);
    this->cabeca = novoNo;

    //cout << "Adicionado Vertice " << novoNo->getIdVertice() << endl;                    /* { DEBUG } */
}

void ListaAdjVertice::adicionar_aresta(int origem, int destino, float peso) {
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getIdVertice() == origem) {
            atual->adicionar_aresta(destino, peso);
        }
        atual = atual->getProximo();
    }
}

void ListaAdjVertice::remover_aresta(int origem, int destino) {
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getIdVertice() == origem) {
            atual->remover_aresta(destino);
        }
        atual = atual->getProximo();
    }
}

void ListaAdjVertice::remover_primeira_aresta(int id) {
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getIdVertice() == id) {
            atual->remover_primeira_aresta();
        }
        atual = atual->getProximo();
    }
}

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