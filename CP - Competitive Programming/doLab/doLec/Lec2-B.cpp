// https://vjudge.net/problem/UVA-12346#author=main
#include <iostream>
using namespace std;

const int N = 30;
const long long INF = 0x3f3f3f3f3f3f3f3f;
struct gate
{
    int flowRate;
    int cost;
} a[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int f, c;
        cin >> f >> c;
        a[i].flowRate = f;
        a[i].cost = c;
    }

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int volu, tim;
        cin >> volu >> tim;
        long long totalCost = INF;

        // 对每一个用例都进行二进制枚举
        for (int k = 0; k <= ((1 << n) - 1); k++)
        {
            long long myvolu = 0, mycost = 0;
            for (int j = 0; j < n; j++)
            {
                if ((k >> j) & 1)
                {
                    myvolu += a[j].flowRate * tim;
                    mycost += a[j].cost;
                }
            }

            if (myvolu >= volu)
            {
                totalCost = min(totalCost, mycost);
            }
        }

        if (totalCost == INF)
            printf("Case %d: IMPOSSIBLE\n", i + 1);
        else
            printf("Case %d: %lld\n", i + 1, totalCost);
    }
    return 0;
}