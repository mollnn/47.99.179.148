#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, q;
int a[2005][2005];
int val; 

void solve()
{
    cin >> n >> m >> val;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int i = n, j = 1;
    while (0 < i && i <= n && 0 < j && j <= m)
    {
        if (a[i][j] == val)
        {
            cout << "true" << endl;
            goto X;
        }
        else if (a[i][j] < val)
            ++j;
        else
            --i;
    }
    cout << "false" << endl;
X:;
}

signed main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        solve();
}