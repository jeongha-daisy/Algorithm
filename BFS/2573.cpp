#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int map[301][301];
bool visited[301][301];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> q;

void print_map()
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << map[i][j] << " ";
        cout << endl;
    }
}
void BFS()
{
    // 1년 후 녹는 과정
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
                if (map[nx][ny] == 0 && !visited[nx][ny] && map[x][y] != 0)
                {
                    map[x][y] -= 1;
                }
                else if (map[nx][ny] != 0 && !visited[nx][ny])
                {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }
}
void solution()
{
    int t = 0;
    while (true)
    {
        int count = 0;
        // print_map();

        memset(visited, false, sizeof(visited));

        // 큐가 비었다면 빙산이 모두 녹은 것
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] != 0 && !visited[i][j])
                {
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                    BFS();
                    count++;
                }
            }
        }
        if (count == 0)
        {
            cout << count;
            return;
        }

        if (count >= 2)
        {
            cout << t;
            return;
        }

        // print_map();

        t++;
    }
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    solution();
    return 0;
}