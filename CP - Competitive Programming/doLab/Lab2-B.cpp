#include <iostream>
#include <list>
#include <unordered_set>
using namespace std;
struct hashfun{
    size_t operator()(const list<int>& l) const{
        size_t res = 0;
        for (int e : l)
        {
            res = res * 131 + e;
        }
        return res;
    }
};

unordered_set<list<int>, hashfun> st;

list<int> samll(list<int> a, list<int> b)
{
    list<int> cpa = a, cpb = b;
    for (int i = 0; i < 6; i++)
    {
        if (a.front() == b.front())
        {
            a.pop_front();
            b.pop_front();
            continue;
        }
        return a.front() < b.front() ? cpa : cpb;
    }
    return cpa;
}

void same(list<int> &s)
{
    list<int> res = s;
    for (int i = 0; i < 5; i++)
    {
        s.push_back(s.front());
        s.pop_front();
        res = samll(res, s);
    }
    s.reverse();
    res = samll(res, s);
    for (int i = 0; i < 5; i++)
    {
        s.push_back(s.front());
        s.pop_front();
        res = samll(res, s);
    }
    s = res;
}

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        list<int> s;
        for (int j = 0; j < 6; j++)
        {
            int t; cin >> t;
            s.push_back(t);
        }
        same(s);
        if (st.count(s))
        {
            cout << "Twin snowflakes found." << '\n';
            return 0;
        }
        else
        {
            st.insert(s);
        }
    }
    cout << "No two snowflakes are alike." << '\n';
    return 0;
}