#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[51];
int b[51];
int answer;

bool compare(int a, int b)
{
    return a > b;
}
void solution()
{
    sort(a, a + n, compare);
    sort(b, b + n);

    for (int i = 0; i < n; i++)
    {
        answer += a[i] * b[i];
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
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    solution();
    return 0;
}