#include <cmath>
#include "NumericalMethods.hpp"
double *globalA;
using namespace std;
#include <iomanip>

//Função
double rocketFunction(double d)
{
    // f(d) = a*d – d*ln(d),
    return (*globalA) * d - d * log(d);
}
//Derivada
double derivativeRocketFunction(double d)
{
    return ((*globalA) - 1) - log(d);
}
int main(int argc, char **argb)
{
    double a = 4;
    globalA = &a;

    double n, err1, err2, input;
    int option;

    cout << "---------------------------------------------------" << endl;
    cout << "Digite um número correspondente ao que deseja fazer:" << endl;
    cout << "---------------------------------------------------" << endl;

    cout << "1 - Calcular com valores padrao ( a = 1; intervalo = [2, 3]; precisao = 10^-5 )" << endl;
    cout << "2 - Quadro resposta e comparativo" << endl;
    cout << "3 - Calcular com valores personalizados" << endl;
    cout << "---------------------------------------------------" << endl;
    cin >> option;

    if (option == 1)
    {
        double a = 1;
        globalA = &a;
        cout
            << "|"
            << "     "
            << "a"
            << "     "
            << "|"
            << "     "
            << "Bisseção"
            << "     "
            << "|"
            << "     "
            << "Posição Falsa"
            << "     "
            << "|"
            << "     "
            << "Newton Raphson"
            << "     "
            << "|"
            << "     "
            << "Isolamento"
            << "     "
            << "|"
            << '\n'
            << "------------------------------------------------------------------------------------------------------" << '\n';

        std::cout
            << "|"
            << "   "
            << fixed << setprecision(3)
            << a
            << "   "
            << "|"
            << "     "
            << fixed << setprecision(5)
            << bisecction(rocketFunction, 2, 3, pow(10, -5))
            << "      "
            << "|"
            << "\t" << falsePosition(rocketFunction, 2, 3, pow(10, -5), pow(10, -5))
            << "        "
            << "|"
            << "\t" << newtonRaphson(rocketFunction, derivativeRocketFunction, 2, pow(10, -5), pow(10, -5))
            << "         "
            << "|"
            << "\t"
            << fixed << setprecision(0)
            << "["
            << "2"
            << ","
            << "3"
            << "]"
            << "        "
            << "|" << '\n';
    }
    if (option == 2)
    {
        cout
            << "|"
            << "     "
            << "a"
            << "     "
            << "|"
            << "     "
            << "Bisseção"
            << "     "
            << "|"
            << "     "
            << "Posição Falsa"
            << "     "
            << "|"
            << "     "
            << "Newton Raphson"
            << "     "
            << "|"
            << "     "
            << "Isolamento"
            << "     "
            << "|"
            << '\n'
            << "------------------------------------------------------------------------------------------------------" << '\n';

        for (a = 0.01; a <= 1.01; a += 0.05)
        {
            double intervalB;
            for (intervalB = 1; rocketFunction(intervalB) >= 0; intervalB++)
                ;

            using std::setw;
            cout << std::left;

            std::cout
                << "|"
                << "   "
                << fixed << setprecision(3)
                << a
                << "   "
                << "|"
                << "     "
                << fixed << setprecision(5)
                << bisecction(rocketFunction, intervalB - 1, intervalB, pow(10, -5))
                << "      "
                << "|"
                << "\t" << falsePosition(rocketFunction, intervalB - 1, intervalB, pow(10, -5), pow(10, -5))
                << "        "
                << "|"
                << "\t" << newtonRaphson(rocketFunction, derivativeRocketFunction, intervalB - 1, pow(10, -5), pow(10, -5))
                << "         "
                << "|"
                << "\t"
                << fixed << setprecision(0)
                << "[" << intervalB - 1 << "," << intervalB << "]"
                << "        "
                << "|" << '\n';
        }
    }
}
