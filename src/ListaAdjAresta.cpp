#include "../include/ListaAdjAresta.h"
#include "../include/NoAresta.h"
#include <iostream>

using namespace std;

ListaAdjAresta::ListaAdjAresta() {
    this->cabeca = nullptr;
}

ListaAdjAresta::~ListaAdjAresta() {
    NoAresta* atual = this->cabeca;
    while (atual != nullptr) {
        NoAresta* next = atual->getProximo();
        delete atual;
        atual = next;
    }
}

NoAresta* ListaAdjAresta::getCabeca() {
    return this->cabeca;
}

void ListaAdjAresta::adicionar_aresta(int origem, int destino, int peso) {
    // Verifica se a aresta ja existe
    NoAresta* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getOrigem() == origem && atual->getDestino() == destino) {
            cout << "Erro: Aresta " << origem << " -> " << destino << " ja existe." <<  endl;
            return;
        }
        atual = atual->getProximo();
    }

    // Adiciona uma nova aresta
    NoAresta* novaAresta = new NoAresta(origem, destino, peso);
    novaAresta->setProximo(this->cabeca);
    this->cabeca = novaAresta;
    cout << "Adicionada Aresta " << novaAresta->getOrigem() << " -> " << novaAresta->getDestino() << endl;
}