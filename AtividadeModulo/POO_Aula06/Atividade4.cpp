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

    }
};

int main(){
    Aluno aluno1("Rafael", 6, 9);

    aluno1.mostrarResultado();

    return 0;
}
