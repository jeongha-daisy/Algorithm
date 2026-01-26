#include <iostream>
using namespace std;

int numbers[101];
int n;
int answer;
void solution()
{
    int pre_n = numbers[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (pre_n <= numbers[i])
        {

            int gap = numbers[i] - pre_n + 1;
            answer += gap;
            pre_n = numbers[i] - gap;
        }
        else
        {
            pre_n = numbers[i];
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
    }
    solution();
    return 0;
}