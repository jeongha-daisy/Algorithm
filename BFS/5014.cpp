#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1000001
int v[MAX];
int visited[MAX];
int F, S, G, U, D;
queue<int> q;

void solution()
{

    v[S] = 0;
    if (S == G)
    {
        cout << v[S];
        return;
    }

    q.push(S);
    visited[S] = true;
    while (!q.empty())
    {
        int floor = q.front();
        q.pop();

        // UP 이동
        if (floor + U <= F && !visited[floor + U])
        {
            q.push(floor + U);
            v[floor + U] = v[floor] + 1;
            visited[floor + U] = true;
            if (floor + U == G)
            {
                cout << v[G];
                return;
            }
        }

        // DOWN 이동
        if (floor - D > 0 && !visited[floor - D])
        {
            q.push(floor - D);
            v[floor - D] = v[floor] + 1;
            visited[floor - D] = true;
            if (floor - D == G)
            {
                cout << v[G];
                return;
            }
        }
    }
    cout << "use the stairs";
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> F >> S >> G >> U >> D;
    solution();
    return 0;
}