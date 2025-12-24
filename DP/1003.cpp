#include <iostream>
using namespace std;

int n;
int fib[41][2];

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    // fib(0)에서 0이 출력되는 수는 1번, 1이 출력되는 수는 0번
    fib[0][0] = 1;
    fib[0][1] = 0;

    // fib(1)에서 0이 출력되는 수는 0번, 1이 출력되는 수는 1번
    fib[1][0] = 0;
    fib[1][1] = 1;

    // fib(2)에서 0이 출력되는 수는 1번, 1이 출력되는 수는 1번
    fib[2][0] = 1; // fib(0)
    fib[2][1] = 1; // fib(1)

    for (int i = 3; i < 41; i++)
    {
        fib[i][0] = fib[i - 1][0] + fib[i - 2][0];
        fib[i][1] = fib[i - 1][1] + fib[i - 2][1];
    }

    while (n--)
    {
        int a;
        cin >> a;

        cout << fib[a][0] << " " << fib[a][1] << endl;
    }
    return 0;
}