#include <iostream>
using namespace std;

int t;
int n;
int stickers[2][100001];
int scores[2][100001]; // 각 스티커를 뽑았을 때 최대 점수

void solution()
{
    scores[0][0] = stickers[0][0]; // 첫 번째 스티커를 뽑는 경우
    scores[1][0] = stickers[1][0];

    if (n > 1)
    {
        // 두 번째 스티커를 뽑는 경우는 첫번째의 교차된 스티커를 뽑는 경우
        scores[0][1] = stickers[0][1] + scores[1][0];
        scores[1][1] = stickers[1][1] + scores[0][0];
    }

    for (int i = 2; i < n; i++)
    {
        scores[0][i] = stickers[0][i] + max(scores[1][i - 1], scores[1][i - 2]);

        scores[1][i] = stickers[1][i] + max(scores[0][i - 1], scores[0][i - 2]);
    }

    cout << max(scores[0][n - 1], scores[1][n - 1]) << '\n';
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
        for (int j = 0; j < 2; j++)
            for (int i = 0; i < n; i++)
                cin >> stickers[j][i];

        solution();
    }

    return 0;
}