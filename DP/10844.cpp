#include <iostream>
using namespace std;

#define DIVISOR 1000000000
int n;
int dp[101][10];

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 1; i < 10; i++)
        dp[0][i] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j != 0)
                dp[i][j] += dp[i - 1][j - 1] % DIVISOR;
            if (j != 9)
                dp[i][j] += dp[i - 1][j + 1] % DIVISOR;
        }
    }

    long int answer = 0;
    for (int i = 0; i < 10; i++)
        answer += dp[n - 1][i];
    cout << answer % DIVISOR;
    return 0;
}