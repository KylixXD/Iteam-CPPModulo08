/*
 Aula 6 - 15/06/2026
 Linguagem de Programação C++
 Profa. Erika Dilly
 Vetores e Orientação a objetos em C++
*/

#include <iostream>
#include <string>

using namespace std;

class Aluno{
    private: 
        string nome;
        float nota1;
        float nota2;

    public:

    Aluno(string nome, float nota1, float nota2){
        this -> nome = nome;
        this -> nota1 = nota1;
        this -> nota2 = nota2;
    }

    double calcularMedia(){
        return((nota1 + nota2)/2);
    }

    void mostrarResultado(){
        double media = calcularMedia();

        cout << "Aluno: " << this -> nome << endl;
        cout << "Média: " << media << endl;
     
        if(media >= 7.0){
            cout << "Situação: Aprovado" << endl;
        } else {
            cout << "Situação: Reprovado" << endl;
        }

    }
};

int main(){
    Aluno aluno1("Rafael", 6, 9);

    aluno1.mostrarResultado();

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

class ContaBancaria {
    private:
        string titular;
        double saldo;

    public:
        ContaBancaria(string titular, double saldoInicial) {
            this->titular = titular;
            this->saldo = saldoInicial;
        }

        void depositar(double valor) {
            if (valor > 0) {
                this->saldo += valor;
                cout << "Depósito de R$ " << valor << " realizado com sucesso!" << endl;
            } else {
                cout << "Valor de depósito inválido!" << endl;
            }
        }

        void sacar(double valor) {
            if (valor > 0 && valor <= this->saldo) {
                this->saldo -= valor;
                cout << "Saque de R$ " << valor << " realizado com sucesso!" << endl;
            } else if (valor > this->saldo) {
                cout << "Saldo insuficiente para realizar o saque de R$ " << valor << "!" << endl;
            } else {
                cout << "Valor de saque inválido!" << endl;
            }
        }

        void mostrarSaldo() {
            cout << "-----------------------------------" << endl;
            cout << "Titular da Conta: " << this->titular << endl;
            cout << "Saldo Atual: R$ " << this->saldo << endl;
            cout << "-----------------------------------" << endl;
        }
};

int main() {
    ContaBancaria conta1("Rafael", 1000.0);
    

    conta1.mostrarSaldo();
    conta1.depositar(500.0);

    conta1.sacar(300.0);
    conta1.mostrarSaldo();

    return 0;
}
