/*
 Aula 7 - 16/06/2026
 Linguagem de Programação C++
 Profa. Erika Dilly
 Encapsulamento
*/

#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

class Carro {
private:
    string marca;
    double velocidade;

public:
    Carro(string marca) {
        this->marca = marca;
        this->velocidade = 0;
    }

    string getMarca() const {
        return marca;
    }

    double getVelocidade() const {
        return velocidade;
    }

    void acelerar(double valor) {
        if (valor > 0) {
            velocidade += valor;
            cout << "O " << marca << " acelerou. Velocidade atual: " << velocidade << " km/h." << endl;
        } else {
            cout << "Valor de aceleração deve ser positivo!" << endl;
        }
    }

    void frear(double valor) {
        if (valor > 0) {
            if (velocidade - valor < 0) {
                velocidade = 0;
            } else {
                velocidade -= valor;
            }
            cout << "O " << marca << " freou. Velocidade atual: " << velocidade << " km/h." << endl;
        } else {
            cout << "Valor de frenagem deve ser positivo!" << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    Carro meuCarro("Nissan");

    cout << "====== Testando o Carro (" << meuCarro.getMarca() << ") =========" << endl;
    cout << "Velocidade Inicial: " << meuCarro.getVelocidade() << " km/h." << endl;

    meuCarro.acelerar(120);
    meuCarro.acelerar(40);
     cout << "Velocidade após as Acelarações : " << meuCarro.getVelocidade() << " km/h." << endl; 

    meuCarro.frear(30);
    meuCarro.frear(90);
    meuCarro.frear(50);
    cout << "Velocidade final depois do uso dos freios: " << meuCarro.getVelocidade() << " km/h." << endl; 

    return 0;
}