#include <iostream>
#include <algorithm>
using namespace std;

int n;
int costs[1000][3];
int answers[1000][3];

void solution()
{
    answers[0][0] = costs[0][0];
    answers[0][1] = costs[0][1];
    answers[0][2] = costs[0][2];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            answers[i][j] = min(answers[i - 1][(j + 1) % 3], answers[i - 1][(j + 2) % 3]) + costs[i][j];
        }
    }

    int answer = min(answers[n - 1][0], answers[n - 1][1]);
    cout << min(answer, answers[n - 1][2]);
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
    }

    solution();
    return 0;
}