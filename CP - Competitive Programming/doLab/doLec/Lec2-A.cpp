// https://vjudge.net/problem/UVA-10041#author=user:1125911
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 510;

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a[N], res = 0;
        int num; cin >> num;

        for (int j = 1; j <= num; j++) 
        {
            int p; cin >> p;
            a[j] = p;
        }
        sort(a + 1, a + 1 + num);

        int phouse = a[num / 2 + 1];
        for (int j = 1; j <= num; j++)
        {
            res += abs(a[j] - phouse);
        }
        cout << res << endl;
    }
    return 0;
}