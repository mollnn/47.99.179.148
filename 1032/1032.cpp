#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        n--;
        int s = 0, x = 0;
        for (int i = 1; i <= n; i++)
            cin >> x, s += x;
        cout << fixed << setprecision(6) << (1.0 + 0.01 * s) << endl;
    }
}