#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000000
#define DIVISOR 1000000009

int t;
vector<int> answers;
long int dp[MAX + 1];

void solution()
{
    dp[1] = 1; // 1
    dp[2] = 2; // 1+1, 2
    dp[3] = 4; // 1+2, 1+1+1, 2+1, 3

    for (int i = 4; i < MAX + 1; i++)
    {
        dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % DIVISOR;
    }

    while (t--)
    {
        int n;
        cin >> n;
        answers.push_back(dp[n]);
    }

    for (int answer : answers)
        cout << answer << " \n";
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    solution();
    return 0;
}