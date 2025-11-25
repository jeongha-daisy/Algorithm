#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int map[51][51];
bool visited[51][51];
int testcase;
queue<pair<int, int>> q;
vector<int> answer;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS(int n, int m)
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
            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                if (!visited[nx][ny] && map[nx][ny] == 1)
                {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

void solution()
{
    for (int t = 0; t < testcase; t++)
    {
        int m, n, k, count = 0;
        cin >> m >> n >> k;

        // map, visited 초기화
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));

        // 배추
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            map[x][y] = 1;
        }

        // 탐색
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && map[i][j] == 1)
                {
                    count++;
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                    BFS(n, m);
                }
            }
        }

        answer.push_back(count);
    }

    for (int a : answer)
    {
        cout << a << endl;
    }
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> testcase;
    solution();
    return 0;
}