#include <iostream>
using namespace std;

int n;
// 使用递归的方式实现
int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

// // 使用循环的方式实现
// int fact(int n)
// {
//     int res = 1;
//     for (int i = 1; i <= n; i++) res *= i;
//     return res;
// }

int main()
{
    cin >> n;
    cout << fact(n) << endl;
    return 0;
}