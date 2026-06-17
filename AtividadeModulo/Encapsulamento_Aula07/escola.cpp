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

class Aluno
{
private:
    string nome;
    int idade;
    string curso;

public:
    Aluno(string nome, int idade, string curso)
    {
        this->nome = nome;
        this->idade = idade;
        this->curso = curso;
    }

    string getNome() const
    {
        return nome;
    }

    int getIdade() const
    {
        return idade;
    }

    string getCurso() const
    {
        return curso;
    }

    void setNome(string novo_nome)
    {
        if (!novo_nome.empty())
        {
            nome = novo_nome;
        }
        else
        {
            cout << "Nome invalido!" << endl;
        }
    }

    void setIdade(int nova_idade)
    {
        if (nova_idade > 0)
        {
            idade = nova_idade;
        }
        else
        {
            cout << "Idade invalida!" << endl;
        }
    }

    void setCurso(string novo_curso)
    {
        if (!novo_curso.empty())
        {
            curso = novo_curso;
        }
        else
        {
            cout << "Curso invalido!" << endl;
        }
    }

    string apresentar() const
    {
        return "Nome: " + nome +
               " | Idade: " + to_string(idade) +
               " | Curso: " + curso;
    }
};

class Escola
{
private:
    string nome;
    vector<Aluno> alunos;

public:
    Escola(string nome)
    {
        this->nome = nome;
    }

    string getNome() const
    {
        return nome;
    }

    void setNome(string novo_nome)
    {
        if (!novo_nome.empty())
        {
            nome = novo_nome;
        }
        else
        {
            cout << "Nome invalido!" << endl;
        }
    }

    void adicionarAluno(Aluno aluno)
    {
        alunos.push_back(aluno);
    }

    void listarAlunos() const
    {

        if (alunos.empty())
        {
            cout << "Nenhum aluno matriculado." << endl;
            return;
        }

        cout << "\n--- Alunos da " << nome << " ---" << endl;

        for (Aluno aluno : alunos)
        {
            cout << aluno.apresentar() << endl;
        }
    }
};

int main()
{

    Escola escola("Escola Futuro");

    Aluno aluno1("Joao", 20, "Informatica");
    Aluno aluno2("Maria", 18, "Assistente Social");

    escola.adicionarAluno(aluno1);
    escola.adicionarAluno(aluno2);

    escola.listarAlunos();

    cout << "\nTestando alteracoes..." << endl;

    aluno2.setIdade(24);
    aluno1.setCurso("Medicina Veterinaria");

    cout << aluno1.apresentar() << endl;
    cout << aluno2.apresentar() << endl;

    return 0;
}