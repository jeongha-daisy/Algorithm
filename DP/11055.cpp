#include <iostream>
#include <algorithm>
using namespace std;

int n;
int numbers[1001];
int cumulativeSum[1001];

void solution()
{
    int answer = cumulativeSum[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (numbers[i] < numbers[j])
            {
                cumulativeSum[j] = max(cumulativeSum[j], cumulativeSum[i] + numbers[j]);
                answer = max(answer, cumulativeSum[j]);
            }
        }
    }
    cout << answer;
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
        cumulativeSum[i] = numbers[i];
    }

    solution();
    return 0;
}