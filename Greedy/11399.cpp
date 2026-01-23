#include <iostream>
#include <algorithm>
using namespace std;

int n;
int p[1001];
int answer;

void solution()
{
    sort(p, p + n);
    answer += p[0];
    for (int i = 1; i < n; i++)
    {
        p[i] += p[i - 1];
        answer += p[i];
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
        cin >> p[i];
    }
    solution();
    return 0;
}