#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n;
int numbers[1001];
int LIS[1001][2];
int last_idx = 0;

void solution()
{
    int answer = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // 현재 숫자보다 다음 숫자가 크면 증가하는 수열
            if (numbers[i] < numbers[j])
            {
                if (LIS[j][0] < LIS[i][0] + 1)
                {
                    LIS[j][0] = LIS[i][0] + 1;
                    LIS[j][1] = i;
                }

                if (answer < LIS[j][0])
                {
                    answer = LIS[j][0];
                    last_idx = j;
                }
            }
        }
    }
    cout << answer << endl;
    stack<int> arr;

    while (answer--)
    {
        arr.push(numbers[last_idx]);
        last_idx = LIS[last_idx][1];
    }
    while (!arr.empty())
    {
        cout << arr.top() << " ";
        arr.pop();
    }
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
        LIS[i][0] = 1;
    }

    solution();
    return 0;
}