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

class Restaurante {
private:
    string nome;
    vector<string> cardapio;

public:
    Restaurante(string nome) {
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

    void adicionarPrato(string prato) {
        for (string item : cardapio) {
            if (item == prato) {
                cout << "O prato \"" << prato << "\" ja existe no cardapio." << endl;
                return;
            }
        }

        cardapio.push_back(prato);
        cout << prato << " adicionado ao cardapio." << endl;
    }

    void atenderCliente(string nome_cliente, string prato) {
        for (string item : cardapio) {
            if (item == prato) {
                cout << nome_cliente
                     << ", seu pedido de "
                     << prato
                     << " foi confirmado!" << endl;
                return;
            }
        }

        cout << "Infelizmente, "
             << nome_cliente
             << ", o prato "
             << prato
             << " nao existe no nosso cardapio." << endl;
    }

    void listarCardapio() const {
        cout << "\n--- Cardapio de " << nome << " ---" << endl;

        for (string prato : cardapio) {
            cout << "- " << prato << endl;
        }
    }


};

int main() {

    Restaurante restaurante("Sabor Caseiro");

    restaurante.adicionarPrato("Macarronada");
    restaurante.adicionarPrato("Lasanha");
    restaurante.adicionarPrato("Peixe a Delicia");

    restaurante.listarCardapio();

    cout << endl;

    restaurante.atenderCliente("Rafael", "Lasanha");
    restaurante.atenderCliente("Maria Eduarda", "Sopa");

    cout << "\nNome atual do Restaurante: "
         << restaurante.getNome()
         << endl;

    restaurante.setNome("Divino Sabor");

    cout << "Novo nome do Restaurante: "
         << restaurante.getNome()
         << endl;

    return 0;
}