#include <stdio.h>
#include <math.h>

double function(double x);
void sequentialRectangle(int a, int b, int n);
void sequentialTrapeze(double a, double b, int n);

int main()
{
    double lower = 0, upper = 1, n = 5;

    sequentialRectangle(lower, upper, n);
    sequentialTrapeze(lower, upper, n);
    return 0;
}

double function(double x)
{
    return sin(x);
}

void sequentialRectangle(int a, int b, int n)
{
    double h = (b-a)/n;
    double x = 0, value = 0;

    for(int i = 0; i < n; i++)
    {
        x = a + i*h + h/2;
        value += h*function(x);
    }

    printf("Approximate integral with rectangle formula: %.4f\n", value);
}

void sequentialTrapeze(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0.5 * (function(a) + function(b));
    double x = 0;

    for(int i = 1; i < n; i++)
    {
        x = a + i * h;
        sum += function(x);
    }
    x = h * sum;

    printf("Approximate integral with trapeze formula: %.4f\n", x);
}