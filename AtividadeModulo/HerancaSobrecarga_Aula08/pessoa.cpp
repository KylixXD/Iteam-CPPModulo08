#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pessoa {
    protected:
        string nome;

    public:
        Pessoa(string n) : nome(n) {}

        virtual void falar(){
            cout << nome << " está falando." << endl;
        }
};

class Professor : public Pessoa{
    private:
        string disciplina;

    public:
        Professor(string n, string d) : Pessoa(n), disciplina(d){}

        void falar() override {
            cout << "Professor(a) " << nome << " está ensinando " << disciplina << "." << endl;
        }
};

class Aluno : public Pessoa {
    private:
        int matricula;

    public:
        Aluno(string n, int m) : Pessoa(n), matricula(m) {}

        void falar() override {
            cout << "Aluno(a) " << nome << " (matrícula:  " << matricula << " ) está aprendendo." << endl;
        }
};

void fazerFalar(Pessoa* p){
    p->falar();
}

int main(){
    Pessoa* p1 = new Pessoa("Rafael");
    Pessoa* p2 = new Professor("Maria", "Ciência");
    Pessoa* p3 = new Aluno("Marco", 201);

    fazerFalar(p1);
    fazerFalar(p2);
    fazerFalar(p3);

    delete p1;
    delete p2;
    delete p3;

    return 0;
}