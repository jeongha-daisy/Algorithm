#include <iostream>
using namespace std;

#define MAX 1000000000

int n;
int f[1000001];

void solution()
{
    f[0] = 0;

    if (n > 0)
    {
        f[1] = 1;
        f[2] = 1;
        for (int i = 3; i < n + 1; i++)
        {
            f[i] = (f[i - 1] + f[i - 2]) % MAX;
        }
        cout << 1 << endl
             << f[n];
        return;
    }
    else
    {
        f[1] = 1;
        f[2] = -1;
        for (int i = 3; i < abs(n) + 1; i++)
        {
            f[i] = (f[i - 2] - f[i - 1]) % MAX;
        }
        cout << (f[abs(n)] > 0 ? 1 : -1) << endl
             << abs(f[abs(n)]);
    }
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if (n == 0)
    {
        cout << 0 << endl
             << 0;
        return 0;
    }

    solution();
    return 0;
}