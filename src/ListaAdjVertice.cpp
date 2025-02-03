#include "../include/ListaAdjVertice.h"
#include "../include/NoVertice.h"
#include <iostream>

using namespace std;

ListaAdjVertice::ListaAdjVertice() {
    this->cabeca = nullptr;
}

ListaAdjVertice::~ListaAdjVertice() {
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        NoVertice* next = atual->getProximo();
        delete atual;
        atual = next;
    }
}

NoVertice* ListaAdjVertice::getCabeca() {
    return this->cabeca;
}

int ListaAdjVertice::getNumVertices() {
    int tamanho = 0;
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        tamanho++;
        atual = atual->getProximo();
    }
    return tamanho;
}

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

void ListaAdjVertice::adicionar_vertice(int id, int peso) {
    // Verifica se o vértice já existe
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getIdVertice() == id) {
            cout << "Erro: Vertice " << id << " ja existe." <<  endl;
            return;
        }
        atual = atual->getProximo();
    }

    // Adiciona um novo vértice
    NoVertice* novoNo = new NoVertice(id, peso);
    novoNo->setProximo(this->cabeca);
    this->cabeca = novoNo;
    cout << "Adicionado Vertice " << novoNo->getIdVertice() << endl;
}

void ListaAdjVertice::adicionar_aresta(int origem, int destino, int peso) {
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getIdVertice() == origem) {
            atual->adicionar_aresta(destino, peso);
        }
        atual = atual->getProximo();
    }
}

void ListaAdjVertice::imprimir() {
    cout << "__________________________________________________________________" << endl;
    cout << endl << "--- Lista de Adjacencia ---" << endl;
    cout << "__________________________________________________________________" << endl << endl;
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        cout << "Vertice " << atual->getIdVertice() << " -> ";
        NoAresta* atualAresta = atual->getArestas()->getCabeca();
        while (atualAresta != nullptr) {
            cout << atualAresta->getDestino() << " ";
            atualAresta = atualAresta->getProximo();
        }
        cout << endl;
        atual = atual->getProximo();
    }
    cout << "__________________________________________________________________" << endl << endl;
}