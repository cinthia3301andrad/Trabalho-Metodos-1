#include "NumericalMethods.hpp"
#include <iostream>
#include <iomanip>
double bisecction(double (*numFunc)(double), double a, double b, double E)
{
    double Fa = numFunc(a);
    double Fb = numFunc(b);
    if (Fa * Fb > 0)
    {
        std::cout << " Error, no sign change between a and b\t" << std::endl;
        return 0;
    }
    double interVx = fabs(b - a);
    int k = 0;
    double root = 0;

    while (interVx >= E)
    {
        double x = (a + b) / 2;
        double Fx = numFunc(x);
        // using std::setw;
        // std::cout << std::left;
        // std::cout
        //     << setw(5) << "|" << setw(5) << k + 1 << setw(5) << "|" << setw(15) << a << "|" << setw(15) << Fa << "|" << '\n';
        // std::cout
        //     << "----------------------------------------" << '\n';

#ifdef PRINT_ITERATIONS
        std::cout << "\t K= \t" << k + 1 << "\t  a= \t" << a << "\t  Fa= \t" << Fa << "\t b= \t" << b << "\t  x= \t" << x << "\t  Fx= \t" << Fx << "\t  intervX = \t" << interVx << std::endl;
#endif
        if (Fa * Fx > 0)
        {
            a = x;
            Fa = Fx;
        }
        else
        {
            b = x;
            Fb = Fx;
        }
        interVx = interVx / 2;
        k++;
        root = x;
    }
    return root;
}

double falsePosition(double (*numFunc)(double), double a, double b, double E1, double E2)
{
    double Fa = numFunc(a);
    double Fb = numFunc(b);
#ifdef PRINT_ITERATIONS
    std::cout << "\t E1= \t" << E1 << "\t  E2= \t" << E2 << std::endl;
#endif
    if (Fa * Fb > 0)
    {
        std::cout << "\t Error, no sign change between a and b\t" << std::endl;
        return 0.0;
    }
    double interVx = fabs(b - a);
    double root = 0;
    if (interVx < E1)
    {
        root = (a + b) / 2;
    }
    if (fabs(Fa) < E2)
    {
        root = a;
    }
    if (fabs(Fb) < E2)
    {
        root = b;
    }
    int k = 0;
    while (true)
    {
        double x = (a * Fb - b * Fa) / (Fb - Fa);
        double Fx = numFunc(x);
#ifdef PRINT_ITERATIONS
        std::cout << "\t K= \t" << k + 1 << "\t  a=\t" << a << "\t  Fa=\t" << Fa << "\t  b=\t" << b << "\t  x=\t" << x << "\t  Fx=\t" << Fx << "\t  intervX=\t" << interVx << std::endl;
#endif
        if (fabs(Fx) < E2)
        {
            root = x;
            break;
        }
        if (Fa * Fx > 0)
        {
            a = x;
            Fa = Fx;
        }
        else
        {
            b = x;
            Fb = Fx;
        }
        interVx = fabs(b - a);
        if (interVx <= E1)
        {
            root = (a + b) / 2;
            break;
        }

        ++k;
    }
    return root;
}

double newtonRaphson(double (*numFunc)(double), double (*derivative)(double), double x0, double E1, double E2)
{
    if (fabs(numFunc(x0)) < E1)
    {
        return x0;
    }
    int k = 1;
    double x1 = 0;
    while (true)
    {
        x1 = x0 - (numFunc(x0) / derivative(x0));
#ifdef PRINT_ITERATIONS
        std::cout << "\t K= " << k << "\t  X0= \t" << x0 << "\t  X1=\t" << x1 << "\t  f(x0)= " << numFunc(x0) << "\t  f(x1)= \t" << numFunc(x1) << "\t  derivative(x0)=\t" << derivative(x0) << std::endl;
#endif
        //Find a better way to implement this
        if (fabs(numFunc(x0)) < E1 || fabs(x1 - x0) < E2 || k >= 100)
        {
            return x1;
        }
        x0 = x1;
        k++;
    }
}
