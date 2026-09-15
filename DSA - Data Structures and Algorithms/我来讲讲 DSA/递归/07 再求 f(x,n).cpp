#include <iostream>
using namespace std;

double f(double x, int n)
{
    if (n == 1) return x / (x + 1);
    return x / (n + f(x, n - 1));
}


int main()
{
    double x; int n;
    cin >> x >> n;
    printf("%.2lf", f(x, n));
    return 0;
}