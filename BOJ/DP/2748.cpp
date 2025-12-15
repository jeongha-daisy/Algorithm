#include <iostream>

using namespace std;

long int fib[91];
int n;

void solution()
{
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 1;

    for (int i = 3; i < n + 1; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    cout << fib[n];
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solution();
    return 0;
}