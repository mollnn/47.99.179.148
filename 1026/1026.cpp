#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 25;
int n, K;
int a[N];
int f[N][N][N];

void solve()
{
    cin >> n >> K;
    memset(a, 0, sizeof a);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    memset(f, -1, sizeof f);
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            f[i][j][0] = a[j] + (j > i) * f[i][j - 1][0];
    for (int l = 0; l < n; l++)
        for (int i = 0, j = i + l; j < n; i++, j++)
            for (int k = 0; k <= K; k++)
                for (int m = i; m < j; m++)
                    for (int x = 0; x <= k; x++)
                    {
                        if (~f[i][m][x] && ~f[m + 1][j][k - x])
                            f[i][j][k] = max(f[i][j][k], f[i][m][x] + f[m + 1][j][k - x]);
                        if (x < k)
                            if (~f[i][m][x] && ~f[m + 1][j][k - x - 1])
                                f[i][j][k] = max(f[i][j][k], f[i][m][x] * f[m + 1][j][k - x - 1]);
                    }
    cout << f[0][n - 1][K] << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}