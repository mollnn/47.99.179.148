#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 105;

int n, a[N], f[N]; 

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[i] <= a[j])
                f[i] = max(f[i], f[j] + 1);
    }
    cout << *max_element(f + 1, f + n + 1) << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}