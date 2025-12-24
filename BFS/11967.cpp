#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> map[101][101];
bool visited[101][101];
bool lighted[101][101];
queue<pair<int, int>> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int answer = 1;

void BFS()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x][y] = true;

        for (pair<int, int> p : map[x][y])
        {
            if (!lighted[p.first][p.second])
            {
                lighted[p.first][p.second] = true;
                answer++;
                for (int i = 0; i < 4; i++)
                {
                    int nx = p.first + dx[i];
                    int ny = p.second + dy[i];
                    if (nx > 0 && nx <= n && ny > 0 && ny <= n)
                    {
                        // 도달할 수 있는 방
                        if (visited[nx][ny])
                        {
                            q.push(make_pair(p.first, p.second));
                            visited[p.first][p.second] = true;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx > 0 && nx <= n && ny > 0 && ny <= n)
            {
                // 이동한 칸에서 불이 켜져 있고, 방문하지 않았으면
                if (lighted[nx][ny] && !visited[nx][ny])
                {
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}
void solution()
{
    // 입력
    for (int i = 0; i < m; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        map[x][y].push_back(make_pair(a, b));
    }

    // 불이 켜진 1, 1에서 시작
    lighted[1][1] = true;
    visited[1][1] = true;
    q.push(make_pair(1, 1));

    BFS();
    cout << answer;
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    solution();
    return 0;
}