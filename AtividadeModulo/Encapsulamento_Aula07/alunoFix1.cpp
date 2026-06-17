/*
 Aula 7 - 16/06/2026
 Linguagem de Programação C++
 Profa. Erika Dilly
 Encapsulamento
*/

#include <iostream>
#include <string>

using namespace std;

class Aluno{
    private:
    string nome;
    float nota;

    public:

    string getNome() const{
        return nome;
    }

    void setNome(string novoNome){
        if(!novoNome.empty()){
            nome = novoNome;
        }
    }

    float getNota() const{
        return nota;
    }

    void setNota(float novaNota){
        if(novaNota >= 0 && novaNota <= 10){
            nota = novaNota;
            cout << "Nota atualizada para " << novaNota << endl;
        } else {
            cout << "Nota Invalida! Digite um valor entre 0 a 10" << endl;
        }
    }

    void exibirInfo(){
        cout << "Aluno: " << nome << " | Nota: " << nota << endl;
    }

    
};

int main(){
    Aluno a;
    a.setNome("Carlos");
    a.setNota(8.7);
    a.exibirInfo();
    
    Aluno b;
    b.setNome("Leticia");
    b.setNota(83.7);
    b.exibirInfo();


    return 0;
}