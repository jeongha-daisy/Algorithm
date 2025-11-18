#include <iostream>
#include <queue>
using namespace std;

// 전역 변수
int box[501][501] = {};
int visited[501][501] = {};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void BFS(int n, int m, int i, int j)
{

    queue<pair<int, int>> q;

    q.push(make_pair(i, j));
    visited[i][j] += 1;

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
                if (box[nx][ny] == 0 && box[nx][ny] != -1)
                {

                    // cout << "   다음 노드의 위치: " << nx << " " << ny << ", 값: " << visited[nx][ny] << endl;

                    // 아직 방문하지 않은 경우
                    if (visited[nx][ny] == 0)
                    {
                        visited[nx][ny] += visited[x][y] + 1;
                        q.push(make_pair(nx, ny));
                    }
                    // 이미 방문 한 경우 (0도 아니고 벽도 아님)
                    else if (visited[nx][ny] != -1)
                    {
                        if (visited[nx][ny] > visited[x][y] + 1)
                        {
                            visited[nx][ny] = visited[x][y] + 1;
                            q.push(make_pair(nx, ny));
                        }
                    }
                    // 벽인 경우
                    else
                    {
                        continue;
                    }
                }
            }
        }
    }
}

void solution(int n, int m)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (box[i][j] == 1 && !visited[i][j])
            {
                BFS(n, m, i, j);
            }
        }
    }

    int longgest = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0)
            {
                cout << -1;
                return;
            }
            longgest = max(longgest, visited[i][j]);
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
            if (info == -1)
            {
                visited[i][j] = info;
            }
        }
    }
    solution(n, m);
    return 0;
}