#include <iostream>
#include <algorithm>
using namespace std;

int t;
int w;
int plums[1001];
int my_plums[1001][31]; // [t][w] t초까지 w번 이동할 때 먹을 수 있는 자두의 수

void solution()
{
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            // cout << i << "초까지 " << j << "번 이동할 때 먹을 수 있는 자두의 수" << endl;
            if (j % 2 == 0)
            {
                my_plums[i][j] = max({my_plums[i - 1][j], my_plums[i - 1][j - 1], my_plums[i - 1][0]});
                my_plums[i][j] += (plums[i] == 1 ? 1 : 0);
                // cout << "   최대 값은: " << my_plums[i][j] << endl;
            }
            else
            {
                my_plums[i][j] = max({my_plums[i - 1][j], my_plums[i - 1][j - 1]});
                my_plums[i][j] += (plums[i] == 2 ? 1 : 0);
                // cout << "   최대 값은: " << my_plums[i][j] << endl;
            }
        }
        // cout << endl;
    }

    // 최대값
    int answer = 0;
    for (int i = 0; i <= w; i++)
        answer = max(answer, my_plums[t][i]);
    cout << answer;
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t >> w;

    int count = 0;
    for (int i = 1; i <= t; i++)
    {
        cin >> plums[i];
        if (plums[i] == 1)
        {
            count++;
            // i초일 때 한 번도 움직이지 않으면 먹을 수 있는 자두의 수
            my_plums[i][0] = count;
        }
    }

    if (t == 1)
    {
        cout << 1;
        return 0;
    }

    solution();
    return 0;
}