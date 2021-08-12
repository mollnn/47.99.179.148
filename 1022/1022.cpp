#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 505;

int f[N][N];
char s[N], t[N];

void solve()
{
    cin >> s + 1 >> t + 1;
    int n = strlen(s + 1);
    int m = strlen(t + 1);
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i] == t[j])
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            f[i][j] = max(f[i][j], f[i - 1][j]);
            f[i][j] = max(f[i][j], f[i][j - 1]);
        }
    }
    cout << f[n][m] << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
