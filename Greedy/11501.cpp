#include <iostream>
#include <cstring>
using namespace std;

int n, t;
int prices[1000001];
void solution()
{
    int biggest = prices[n - 1];
    long long int answer = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (biggest < prices[i])
        {
            biggest = prices[i];
        }
        else
        {
            answer += biggest - prices[i];
        }
    }
    cout << answer << "\n";
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(prices, 0, sizeof(prices));
        for (int i = 0; i < n; i++)
        {
            cin >> prices[i];
        }
        solution();
    }

    return 0;
}