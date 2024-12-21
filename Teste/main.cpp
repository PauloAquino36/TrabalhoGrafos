#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void carregarArquivo(const string& filename) {
    ifstream arquivo(filename);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << filename << endl;
        return;
    }

    cout << "Arquivo '" << filename << "' carregado com sucesso. Conteudo:" << endl;

    string linha;
    while (getline(arquivo, linha)) {
        cout << linha << endl; // Imprime cada linha do arquivo
    }

    arquivo.close();
    cout << "Leitura concluida!" << endl;
}

void escreverArquivo(const string& filename) {
    ofstream arquivo(filename, ios::app); // 'ios::app' adiciona ao conteúdo existente

    if (!arquivo.is_open()) {
        cerr << "Erro ao criar ou abrir o arquivo: " << filename << endl;
        return;
    }

    string texto;
    cout << "Digite um texto para adicionar ao arquivo (Ctrl + D para terminar):" << endl;
    while (getline(cin, texto)) {
        arquivo << texto << endl;
    }

    arquivo.close();
    cout << "Texto adicionado ao arquivo '" << filename << "' com sucesso!" << endl;
}

int main() {
    string filename = "entrada.txt"; // Caminho relativo ao diretório atual

    // Carregar o arquivo
    carregarArquivo(filename);

    // Escrever no arquivo
    escreverArquivo(filename);

    return 0;
}
