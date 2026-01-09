#include <iostream>
using namespace std;

#define MAX 1000000
int n;
int dp[MAX + 1][2];

void solution()
{
    dp[1][0] = 0;
    dp[1][1] = 0;

    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[3][0] = 1;
    dp[3][1] = 1;

    for (int i = 2; i <= n; i++)
    {
        // 기본적으로 1을 뺀 값을 저장
        dp[i][0] = dp[i - 1][0] + 1;
        dp[i][1] = i - 1;

        // 3으로 나누어지면 3으로 나눈 값과 현재값(1을 뺀 값)을 비교
        if (i % 3 == 0)
        {
            if (dp[i / 3][0] < dp[i][0])
            {
                dp[i][0] = dp[i / 3][0] + 1;
                dp[i][1] = i / 3;
            }
        }

        // else if로 묶으면 2와 3 동시에 나누어 떨어지는 경우는 계산할 수 없으므로 if로 조건을 처리한다.
        // 2로 나누어지면 2로 나눈 값과 현재값(1을 뺀 값 혹은 3으로 나눈 값)을 비교
        if (i % 2 == 0)
        {
            if (dp[i / 2][0] < dp[i][0])
            {
                dp[i][0] = dp[i / 2][0] + 1;
                dp[i][1] = i / 2;
            }
        }
    }

    cout << dp[n][0] << endl;
    int index = n;
    while (index != 0)
    {
        cout << index << " ";
        index = dp[index][1];
    }
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