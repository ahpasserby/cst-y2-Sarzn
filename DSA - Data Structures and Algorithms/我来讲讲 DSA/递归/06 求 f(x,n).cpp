#include <iostream>
#include  <cmath>
using namespace std;

double f(int x, int n)
{
    if (n == 1) return sqrt(1 + x);
    return sqrt(n + f(x, n - 1));

}

int main()
{
    double x; int n;
    cin >> x >> n;
    printf("%.2lf", f(x, n));
    return 0;
}