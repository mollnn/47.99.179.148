#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
const int N = 505;
int a[N];
int f[N][N];

void solve()
{
    cin >> n;
    memset(a, 0, sizeof a);
    memset(f, 0, sizeof f);
    ++n;
    for (int i = 1; i <= n; i++)
    {
        if (i > 1 && i < n)
            cin >> a[i];
        cin >> a[i];
    }
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i < n; i++)
        f[i][i + 1] = 0;
    for (int l = 2; l < n; l++)
    {
        for (int i = 1, j = l + 1; j <= n; i++, j++)
        {
            for (int k = i + 1; k <= j - 1; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
        }
    }
    cout << f[1][n] << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}