#include <iostream>
#include <queue>
#include <string>
using namespace std;

// 전역 변수
int paper[501][501] = {};
int visited[501][501] = {};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int biggest = 0;

int BFS(int n, int m, int i, int j)
{
    int size = 0;
    queue<pair<int, int>> q;

    q.push(make_pair(i, j));
    visited[i][j] += 1;
    size++;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 || nx < n || ny >= 0 || ny < m)
            {
                if (paper[nx][ny] == 1 && !visited[nx][ny])
                {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] += visited[x][y] + 1;
                    size++;
                }
            }
        }
    }

    return visited[n][m];
}

void solution(int n, int m)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (paper[i][j] == 1 && !visited[i][j])
            {
                BFS(n, m, i, j);
            }
        }
    }
    cout << visited[n - 1][m - 1];
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string paint;
        cin >> paint;

        for (int j = 0; j < m; j++)
        {
            paper[i][j] = paint[j] - 48;
        }
    }
    solution(n, m);
    return 0;
}