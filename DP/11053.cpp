#include <iostream>
#include <algorithm>
using namespace std;

int n;
int numbers[1001];
int cumulativeCount[1001];

void solution()
{
    int answer = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (numbers[i] < numbers[j])
            {
                cumulativeCount[j] = max(cumulativeCount[j], cumulativeCount[i] + 1);
                answer = max(answer, cumulativeCount[j]);
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
        cumulativeCount[i] = 1;
    }

    solution();
    return 0;
}