#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int pos[10];

bool check(int a, int b, int c)
{
    int dis = abs(pos[a] - pos[b]);
    if (c > 0 && dis <= c)
        return true;
    else if (c < 0 && dis >= -c)
        return true;
    else
        return false;
    
}

int main()
{
    while (1)
    {
        int cnt = 0;
        int n, m; cin >> n >> m;
        if (n == 0 && m == 0) return 0;

        for (int i = 0; i < n; i++) pos[i] = i;

        int arr1[30], arr2[30], arr3[30];
        for (int i = 0; i < m; i++)
        {
            cin >> arr1[i] >> arr2[i] >> arr3[i];
        }

        do
        {
            bool flag = true;
            for (int i = 0; i < m; i++)
            {
                if (!check(arr1[i], arr2[i], arr3[i])) 
                {
                    flag = false;
                    break;
                }
            }
            if (flag) cnt++;
        } while (next_permutation(pos, pos + n));
        cout << cnt << '\n';
    }
    return 0;
}