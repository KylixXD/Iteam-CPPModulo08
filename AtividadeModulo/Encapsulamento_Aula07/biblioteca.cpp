/*
 Aula 7 - 16/06/2026
 Linguagem de Programação C++
 Profa. Erika Dilly
 Encapsulamento
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Biblioteca {
private:
    string nome;
    vector<string> livros;

public:
    Biblioteca(string nome) {
        this->nome = nome;
    }

    string getNome() const {
        return nome;
    }

    void setNome(string novo_nome) {
        if (!novo_nome.empty()) {
            nome = novo_nome;
        } else {
            cout << "Nome invalido!" << endl;
        }
    }

    void adicionarLivro(string titulo) {

        if (titulo.empty()) {
            cout << "Titulo invalido!" << endl;
            return;
        }

        for (string livro : livros) {
            if (livro == titulo) {
                cout << "O livro \"" << titulo
                     << "\" ja esta cadastrado." << endl;
                return;
            }
        }

        livros.push_back(titulo);
        cout << "Livro \"" << titulo
             << "\" adicionado com sucesso." << endl;
    }

    void listarLivros() const {

        if (livros.empty()) {
            cout << "Nenhum livro cadastrado." << endl;
            return;
        }

        cout << "\n--- Livros da " << nome << " ---" << endl;

        for (string livro : livros) {
            cout << "- " << livro << endl;
        }
    }
};

int main() {

    Biblioteca biblioteca("Biblioteca Central de Roraima");

    biblioteca.adicionarLivro("A cabeça do Santo");
    biblioteca.adicionarLivro("Duna");
    biblioteca.adicionarLivro("Metamorfose");

    // Tentativa de adicionar livro repetido
    biblioteca.adicionarLivro("A cabeça do Santo");

    biblioteca.listarLivros();

    cout << "\nNome atual: "
         << biblioteca.getNome()
         << endl;

    // Alterar nome
    biblioteca.setNome("Biblioteca Municipal de Boa vista");

    cout << "Novo nome: "
         << biblioteca.getNome()
         << endl;

    return 0;
}