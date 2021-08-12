#include <bits/stdc++.h>
using namespace std;

#define int long long
#define lint __int128

const int N = 105;

int a[N];
lint f[N][N], s[N][N];

void solve()
{
    int n, m;
    string str;
    cin >> n >> m >> str;
    memset(a, 0, sizeof a);
    memset(f, 0, sizeof f);
    memset(s, 0, sizeof s);
    ++m;
    for (int i = 1; i <= n; i++)
        a[i] = str[i - 1] - '0';
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            lint base = 1;
            for (int k = j; k >= i; k--)
                s[i][j] += base * a[k], base *= 10;
        }
    for (int i = 1; i <= n; i++)
        f[i][1] = s[1][i];
    for (int k = 2; k <= m; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j < i; j++)
                f[i][k] = max(f[i][k], f[j][k - 1] * s[j + 1][i]);
    cout << (int)f[n][m] << endl;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
        solve();
}