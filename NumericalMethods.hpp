#include <cmath>
#include <iostream>
//#define PRINT_ITERATIONS

 double bisecction( double (*numFunc)( double), double a, double b, double E);
 double falsePosition( double (*numFunc)( double), double a, double b, double E1, double E2);
 double newtonRaphson( double (*numFunc)( double),  double (*derivative)( double), double x0, double E1, double E2);
