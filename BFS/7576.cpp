#include <iostream>
#include <queue>
using namespace std;

// 전역 변수
int box[1001][1001] = {};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void BFS(queue<pair<int, int>> q, int n, int m)
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (box[nx][ny] == 0)
                {
                    box[nx][ny] = box[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

void solution(int n, int m)
{
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (box[i][j] == 1)
            {
                q.push(make_pair(i, j));
            }
        }
    }
    BFS(q, n, m);

    int longgest = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (box[i][j] == 0)
            {
                cout << -1;
                return;
            }
            longgest = max(longgest, box[i][j]);
        }
    }
    cout << longgest - 1;
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int info;
            cin >> info;
            box[i][j] = info;
        }
    }
    solution(n, m);
    return 0;
}