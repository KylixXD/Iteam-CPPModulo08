/*
 Aula 7 - 16/06/2026
 Linguagem de Programação C++
 Profa. Erika Dilly
 Encapsulamento
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Produto
{
private:
    string nome;
    double preco;

public:
    Produto(string nome, double preco)
    {
        this->nome;
        this->preco;
    }

    string getNome()
    {
        return nome;
    }

    double getPreco()
    {
        return preco;
    }

    void setPreco(double novoPreco)
    {
        if (novoPreco > 0)
        {
            preco = novoPreco;
            cout << fixed << setprecision(2);
            cout << "Preço do Produto " << nome << " Atualizado para R$ " << novoPreco << endl;
        }
        else
        {
            cout << "Preço Invalido! O valor deve ser maior que zero. " << endl;
        }
    }

    void exibirInfo()
    {
        cout << fixed << setprecision(2);
        cout << "Produto: " << nome << " | Preço: R$ " << preco << endl;
    }
};

int main()
{
    Produto produto1("Notebook", 3400.00);
    Produto produto2("Desktop", 5300.00);

    produto1.setPreco(-1400);
    produto2.setPreco(100);

    cout << "\n Após atualização dos preços " << endl;

    produto1.exibirInfo();
    produto2.exibirInfo();
}
