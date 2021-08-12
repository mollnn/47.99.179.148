#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 10005;

int f[N];
  
void solve()
{
    int n, k;
    cin >> n >> k;
    memset(f, 0, sizeof f);
    int ans = 0;
    while (f[n] < k && ++ans)
        for (int i = n; i >= 1; i--)
            f[i] += f[i - 1] + 1;
    cout << ans << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}