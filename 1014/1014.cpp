#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 50005;

int a[N], f[N];

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(a, 0, sizeof a);
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            f[i] = max(0ll, f[i - 1]) + a[i];
        cout << *max_element(f + 1, f + n + 1) << endl;
    }
}