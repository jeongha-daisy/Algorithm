#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ropes[100001];
int answer;
bool compare(int a, int b)
{
    return a > b;
}

void solution()
{
    for (int i = n; i > 0; i--)
    {
        answer = max(answer, ropes[i - 1] * i);
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
        cin >> ropes[i];
    }
    sort(ropes, ropes + n, compare);
    solution();
    return 0;
}