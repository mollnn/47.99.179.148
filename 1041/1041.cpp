#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{ 
    int n, m;
    cin >> n >> m;
    vector<int> a(n + m);
    for (int i = 0; i < n + m; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    if ((n + m) & 1)
        cout  << 1.0 * a[(n + m) / 2] << endl;
    else
        cout  << (a[(n + m) / 2] + a[(n + m) / 2 - 1]) * 0.5 << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}