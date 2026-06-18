#include <iostream>
#include <iomanip>
#include <locale.h>
#include <windows.h>

using namespace std;

class Funcionario
{
protected:
    double salario;

public:
    Funcionario(double s) : salario(s) {}

    virtual void mostrarSalario() const
    {
        cout << "Salário do Funcionário: R$ " << fixed << setprecision(2) << salario << endl;
    }

    virtual ~Funcionario() = default;
};

class Gerente : public Funcionario
{
public:
    Gerente(double s) : Funcionario(s) {}

    void mostrarSalario() const override
    {
        double salarioComBonus = salario * 1.20;

        cout << "Salário do Gerente (+20% de bônus): R$ " << fixed << setprecision(2) << salarioComBonus << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "UTF-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Funcionario f1(3000.0);
    f1.mostrarSalario();

    Gerente g1(3000.0);
    g1.mostrarSalario();

    return 0;
}