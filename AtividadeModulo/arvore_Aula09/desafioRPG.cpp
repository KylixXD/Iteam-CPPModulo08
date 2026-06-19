/*
 Aula 9 - 18/06/2026
 Linguagem de Programação C++
 Profa. Erika Dilly
 Encapsulamento
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include <locale.h>
#include <windows.h>

using namespace std;

class Personagem {
    protected:
        string nome;
        int poder;
        string tipo;

    public:
        Personagem(string nome, int poder, string tipo) {
            this -> nome = nome;
            this -> poder = poder;
            this -> tipo = tipo;
        }

        int getPoder(){
            return poder;
        }
        
        virtual void exibir(){
            cout << "Nome: " << nome
                << " | Poder: " << poder
                << " | Tipo: " << tipo;
        };

        virtual ~Personagem() {}
};

class Chefe : public Personagem {
    private:
        string reino;

    public:
        Chefe(string nome, int poder, string tipo, string reino)
            : Personagem(nome, poder, tipo){
                this -> reino = reino;
            }

        void exibir() override{
            cout << "Nome: " << nome
                << " | Poder: " << poder
                << " | Tipo: " << tipo
                << " | Reino: " << reino
                << " (Chefe da Floresta)";

        }
};

class No {
    public:
        Personagem* personagem;
        No* esquerda;
        No* direita;

        No(Personagem* p){
            personagem = p;
            esquerda = nullptr;
            direita = nullptr;
        }
};

class ArvoreBinaria{
    private:
        No* raiz;

        No* inserir(No* no, Personagem* p){
            if( no == nullptr){
                return new No(p);
            }

            if(p->getPoder() < no->personagem->getPoder()){
                no->esquerda = inserir(no->esquerda, p);
            } else {
                no->direita = inserir(no->direita, p);
            }

            return no;
        }

        void emOrdem(No* no){
            if(no == nullptr)
                return;

            emOrdem(no->esquerda);

            no->personagem->exibir();
            cout << endl;

            emOrdem(no->direita);
        }

        public:
            ArvoreBinaria() {
                raiz = nullptr;
            }

            void inserir(Personagem* p){
                raiz = inserir(raiz, p);
            }

            void percorrerEmOrdem(){
                emOrdem(raiz);
            }
};

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    ArvoreBinaria floresta;

    floresta.inserir(new Personagem("Riastan", 11, "Elfo"));
    floresta.inserir(new Personagem("Naranjo", 4, "Humano"));
    floresta.inserir(new Personagem("Eduardo PortãoNovo", 13, "Marinheiro"));
    floresta.inserir(new Personagem("Bessa", 6, "Golira"));

    floresta.inserir(
        new Chefe(
            "Dragão de Olhos Azuis",
            100,
            "Dragão",
            "Montanhas distantes"
        )
    );

    floresta.inserir(
        new Chefe(
            "Quimera",
            60,
            "Monstro",
            "Pantano"
        )
    );

    cout << "Personagens em ordem de Poder: \n \n";

    floresta.percorrerEmOrdem();

    return 0;
}