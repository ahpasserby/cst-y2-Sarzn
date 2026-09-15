#include <iostream>
#include <string>
using namespace std;

string a = "0123456789ABCDEF";

string cvs(int x, int m)
{
    if (x < m) return to_string(x);
    return cvs(x / m, m) + a[x % m];
}

int main()
{
    int x, m; cin >> x >> m;
    cout << cvs(x, m) << endl;
    return 0;
}