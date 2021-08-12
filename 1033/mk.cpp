#include <bits/stdc++.h>
using namespace std;

#define int long long

void gen()
{
    ofstream ofs("input.txt");
    ofs << 1 << endl;
    int n = rand() % 100;
    int m = rand() % 100 + 1;
    ofs << n << endl;
    for (int i = 1; i <= n; i++)
    {
        ofs << rand() % m << " " << rand() % m << endl;
    }
    ofs.close();
}

signed main()
{
    srand(time(NULL));
    int count = 0;
    while (true)
    {
        ++count;
        cout << "count=" << count << endl;
        gen();
        system("1033.exe > stdout.txt");
        system("xk.exe > userout.txt");
        system("cat stdout.txt");
        system("cat userout.txt");
        if (system("fc stdout.txt userout.txt"))
            break;
    }
}