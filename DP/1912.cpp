#include <iostream>
using namespace std;

#define MAX 100000

int numbers[MAX + 1];
int cumulativeSum[MAX + 1];
int n;

void solution()
{

    cumulativeSum[1] = numbers[1];
    int answer = numbers[1];

    for (int i = 2; i < n + 1; i++)
    {
        // 현재값이 누적합 + 현재값 보다 크다면, 현재값부터 새로 누적합을 시작.
        cumulativeSum[i] = max(numbers[i], cumulativeSum[i - 1] + numbers[i]);
        answer = max(answer, cumulativeSum[i]);
    }
    cout << answer;
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 1; i < n + 1; i++)
    {
        cin >> numbers[i];
    }

    solution();
    return 0;
}