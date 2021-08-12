#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 10005;

void solve()
{
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;
    for (int i = 1; i <= 2 * n; i++)
    {
        int x;
        cin >> x;
        if (x)
            a.push_back(i);
        else
            b.push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(a[i] - b[i]);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        solve();
}