#include <iostream>
using namespace std;

int n;
int numbers[1001];

void solution()
{
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i / 2; j++)
        {
            numbers[i] = max(numbers[i], numbers[j] + numbers[i - j]);
        }
    }
    cout << numbers[n];
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> numbers[i];
    }
    solution();
    return 0;
}