#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 505;

double f[N][N], w[N][N], a[N], b[N];
int n;

void solve()
{
    cin >> n;
    int _;
    for (int i = 1; i <= n; i++)
        cin >> _;
    memset(f, 0, sizeof f);
    memset(w, 0, sizeof w);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n + 1; i++)
        w[i][i - 1] = b[i - 1];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            w[i][j] = w[i][j - 1] + a[j] + b[j];
    for (int l = 1; l <= n; l++)
        for (int i = 1, j = l; j <= n; i++, j++)
        {
            f[i][j] = 1e18;
            for (int k = i; k <= j; k++)
                f[i][j] = min(f[i][j], f[i][k - 1] + f[k + 1][j] + w[i][j]);
        }
    cout << fixed << setprecision(6) << f[1][n] << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}