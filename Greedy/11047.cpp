#include <iostream>
using namespace std;

int n, k;
int coins[11];
int answer;

void solution()
{
    while (n--)
    {
        if (coins[n] <= k)
            answer += k / coins[n];
        k %= coins[n];
    }
    cout << answer;
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    solution();
    return 0;
}