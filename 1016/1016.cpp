#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x;
        cin >> x;
        multiset<int> s;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        int flag = 0;
        for (auto i : s)
        {
            if (s.find(x - i) != s.end())
                flag = 1;
        }
        cout << (flag ? "yes" : "no") << endl;
    }
}