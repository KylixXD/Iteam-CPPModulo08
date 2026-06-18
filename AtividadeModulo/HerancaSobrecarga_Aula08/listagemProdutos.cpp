#include <iostream>
#include <string>
#include <locale.h>
#include <windows.h>

using namespace std;

class Produto {
protected:
    string nome;
    double preco;

public:
    Produto(string n, double p) : nome(n), preco(p) {}
    virtual ~Produto() = default;

    virtual void exibirDados() const {
        cout << "Produto: " << nome << " | Preço: R$ " << preco << endl;
    }
};

class Livro : public Produto {
private:
    string autor;

public:
    Livro(string n, double p, string a) : Produto(n, p), autor(a) {}

    void exibirDados() const override {
        cout << "Livro: " << nome 
             << " | Autor: " << autor 
             << " | Preço: R$ " << preco << endl;
    }
};

class Eletronico : public Produto {
private:
    string marca;

public:
    Eletronico(string n, double p, string m) : Produto(n, p), marca(m) {}

    void exibirDados() const override {
        cout << "Eletrônico: " << nome 
             << " | Marca: " << marca 
             << " | Preço: R$ " << preco << endl;
    }
};

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Livro livro1("A Cabeça do Santo", 39.90, "Socorro Acioli");
    Livro livro2("O Alquimista", 49.90, "Paulo Coelho");

    Eletronico eletronico1("Smartphone Poco X5 Pro", 1999.00, "Xiaomi");
    Eletronico eletronico2("Notebook Latitude 3410", 1500.00, "Dell");

    cout << "=== LISTAGEM DE LIVROS ===" << endl;
    livro1.exibirDados();
    livro2.exibirDados();

    cout << "\n=== LISTAGEM DE ELETRÔNICOS ===" << endl;
    eletronico1.exibirDados();
    eletronico2.exibirDados();

    return 0;
}