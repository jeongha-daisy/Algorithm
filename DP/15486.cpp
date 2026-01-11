#include <iostream>
using namespace std;

#define MAX 1500001

int n;
int arr[MAX][2];
int answer[MAX];
int max_count = 0;
void solution()
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (i + arr[i][0] > n)
        {
            answer[i] = answer[i + 1];
        }
        else
        {
            answer[i] = max(answer[i + 1], answer[i + arr[i][0]] + arr[i][1]);
        }
    }

    cout << answer[0];
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    solution();
    return 0;
}