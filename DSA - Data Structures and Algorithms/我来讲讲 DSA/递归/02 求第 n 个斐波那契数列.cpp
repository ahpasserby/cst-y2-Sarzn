#include <iostream>
using namespace std;

// // 使用递归实现
// int fib(int a)
// {
//     if (a == 1 || a == 2) return 1;
//     return fib(a - 1) + fib(a - 2);
// }

// 使用循环实现
int fib(int num)
{
    int a = 1, b = 1, c = 1;
    while (num > 2)
    {
        c = a + b;
        a = b;
        b = c;
        num--;
    }
    return c;
}
int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a; cin >> a;
        cout << fib(a) << endl;
    }
    return 0;
}
