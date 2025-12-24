#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int map[301][301];
bool visited[301][301];
int testcase;
queue<pair<int, int>> q;
vector<int> answer;
int dx[4] = {-2, -1, 1, 2};
int dy[4] = {1, 2, -1, -2};
int direction[8][2] = {
    {-2, 1},
    {-1, 2},
    {1, 2},
    {2, 1},
    {-2, -1},
    {-1, -2},
    {1, -2},
    {2, -1},
};
int n;

void BFS(int c, int d)
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = x + direction[i][0];
            int ny = y + direction[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (!visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    map[nx][ny] += map[x][y] + 1;
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
        cin >> n;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c && b == d)
        {
            answer.push_back(0);
            continue;
        }

        // map, visited 초기화
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));

        // 탐색
        q.push(make_pair(a, b));
        visited[a][b] = true;
        BFS(c, d);

        answer.push_back(map[c][d]);
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