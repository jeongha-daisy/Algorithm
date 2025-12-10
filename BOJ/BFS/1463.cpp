#include <iostream>
#include <queue>
using namespace std;

int numbers[1000001];
bool visited[1000001];
queue<int> q;

void solution()
{
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x % 3 == 0 && x / 3 > 0 && !visited[x / 3])
        {
            numbers[x / 3] += numbers[x] + 1;
            visited[x / 3] = true;
            if (x / 3 == 1)
                cout << numbers[x / 3];
            q.push(x / 3);
        }
        if (x % 2 == 0 && x / 2 > 0 && !visited[x / 2])
        {
            numbers[x / 2] += numbers[x] + 1;
            visited[x / 2] = true;
            if (x / 2 == 1)
                cout << numbers[x / 2];
            q.push(x / 2);
        }
        if (x - 1 > 0 && !visited[x - 1])
        {
            numbers[x - 1] += numbers[x] + 1;
            visited[x - 1] = true;
            if (x - 1 == 1)
                cout << numbers[x - 1];
            q.push(x - 1);
        }
    }
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;
    if (x == 1)
    {
        cout << 0;
        return 0;
    }
    q.push(x);
    visited[x] = true;
    solution();
    return 0;
}