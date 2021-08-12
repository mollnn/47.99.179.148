#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int m;
    cin >> m;
    vector<int> b(999);
    for (int i = 1; i <= m; i++) 
    {
        int x;
        cin >> x;
        b[x] = 1;
    }
    vector<int> f(999, 99999999999999ll);
    int c[4];
    cin >> c[1] >> c[2] >> c[3];
    f[0] = 0;
    for (int _ = 1; _ <= 365; _++)
    {
        for (int i = 365; i >= 1; i--)
            f[i] = min(f[i], f[i - 1] + c[1]);
        for (int i = 365; i >= 7; i--)
            f[i] = min(f[i], f[i - 7] + c[2]);
        for (int i = 365; i >= 30; i--)
            f[i] = min(f[i], f[i - 30] + c[3]);
        for (int i = 365; i >= 1; i--)
            if (b[i] == 0)
                f[i] = min(f[i], f[i - 1]);
    }
    cout << f[365] << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}