#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;
    string str;
    getline(cin, str);
    while (t--)
    {
        string str;
        getline(cin, str);
        int ans = 0;
        for (auto i : str)
            if (i >= '0' && i <= '9')
                ++ans;
        cout << ans << endl;
    }
}