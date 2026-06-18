/*
 Aula 7 - 16/06/2026
 Linguagem de Programação C++
 Profa. Erika Dilly
 Encapsulamento
*/

#include <iostream>
#include <string>
#include <locale>
#include <windows.h>

using namespace std;

class Veiculo
{
protected:
    string marca;

public:
    Veiculo(string m) : marca(m) {}

    virtual void exibirInfo()
    {
        cout << "o carro é da " << marca << " famosa" << endl;
    }
};

class Carro : public Veiculo
{
private:
    string modelo;

public:
    Carro(string marca, string modelo) : Veiculo(marca)
    {
        this->modelo = modelo;
    }

    string getModelo() const
    {
        return modelo;
    }

    void exibirInfo() override
    {
        cout << "O carro é um " << modelo << " da marca " << marca << "." << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "UTF-8");
    SetConsoleCP(CP_UTF8);         
    SetConsoleOutputCP(CP_UTF8);

    Carro meuCarro("Nissan", "GTR R-35");
    meuCarro.exibirInfo();

    return 0;
}