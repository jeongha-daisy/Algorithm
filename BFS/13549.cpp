#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001
#define MIN 0
int map[MAX];
bool visited[MAX];
queue<int> q;

void solution(int n, int k)
{
    if (n == k)
    {
        cout << 0;
        return;
    }
    if (n == 0 && k == MAX - 1)
    {
        cout << 6;
        return;
    }

    q.push(n);
    visited[n] = true;
    map[n] = 0;

    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        if (!visited[2 * a] && 2 * a < MAX && 2 * a >= MIN)
        {
            q.push(2 * a);
            map[2 * a] += map[a];
            visited[2 * a] = true;
            if (2 * a == k)
            {
                cout << map[2 * a];
                return;
            }
        }
        if (!visited[a - 1] && a - 1 < MAX && a - 1 >= MIN)
        {
            q.push(a - 1);
            // 그 전 방문 칸으로부터 1초 추가
            map[a - 1] += map[a] + 1;
            visited[a - 1] = true;
            if (a - 1 == k)
            {
                cout << map[a - 1];
                return;
            }
        }

        if (!visited[a + 1] && a + 1 < MAX && a + 1 >= MIN)
        {
            q.push(a + 1);
            // 그 전 방문 칸으로부터 1초 추가
            map[a + 1] += map[a] + 1;
            visited[a + 1] = true;
            if (a + 1 == k)
            {
                cout << map[a + 1];
                return;
            }
        }
    }
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    solution(N, K);
    return 0;
}