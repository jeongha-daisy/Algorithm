#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long int cards[1001];

void solution()
{
    sort(cards, cards + n);

    while (m--)
    {
        cards[0] += cards[1];
        cards[1] = cards[0];

        sort(cards, cards + n);
    }
    long long int answer = 0;

    for (int i = 0; i < n; i++)
    {
        answer += cards[i];
    }
    cout << answer;
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> cards[i];
    }

    solution();
    return 0;
}