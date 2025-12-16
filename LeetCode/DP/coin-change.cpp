#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    // d[n]은 n을 만들기 위해 필요한 최소한의 동전의 개수
    int d[amount + 1];

    // 만들 수 있는 가장 큰 값으로 초기화.
    fill(d, d + amount + 1, amount + 1);

    // 숫자 0을 만들기 위해 필요한 최소한의 동전 개수는 0개
    d[0] = 0;

    // n을 만들기 위해 필요한 동전을 확인한다. bottom up 방식.
    for (int n = 1; n < amount + 1; n++)
    {
        for (int coin : coins)
        {
            // n을 만들기 위해 coin을 사용했을 때 필요한 남은 양
            int remain = n - coin;

            // remain이 음수면 만들 수 없는 amount.
            if (remain < 0)
                continue;

            // remain을 만들기 위해 필요한 최소한의 coin + 1(현재 사용한 coin 1개)과 현재 저장된 값 중에 더 작은 값을 저장.
            d[n] = min(d[remain] + 1, d[n]);
        }
    }

    return d[amount] != amount + 1 ? d[amount] : -1;
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    int amount;
    cin >> amount;
    vector<int> coins = {2};

    cout << coinChange(coins, amount);
    return 0;
}