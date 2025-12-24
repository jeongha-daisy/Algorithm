#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char paint[101][101];
bool visited[101][101];
queue<pair<int, int>> q;
int n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(char c)
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
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (paint[nx][ny] == c && !visited[nx][ny])
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
    // ============================= 적록색약이 아닌 사람
    // 첫 번째 색으로 BFS 수행
    int count_none = 1;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    BFS(paint[0][0]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                count_none++;
                q.push(make_pair(i, j));
                visited[i][j] = true;
                BFS(paint[i][j]);
            }
        }
    }

    // ============================= 적록색약이 아닌 사람
    // 초기화
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (paint[i][j] == 'G')
                paint[i][j] = 'R';
            visited[i][j] = false;
        }
    }
    // 첫 번째 색으로 BFS 수행
    int count_cb = 1;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    BFS(paint[0][0]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                count_cb++;
                q.push(make_pair(i, j));
                visited[i][j] = true;
                BFS(paint[i][j]);
            }
        }
    }
    cout << count_none << " " << count_cb;
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            paint[i][j] = c;
        }
    }
    solution();
    return 0;
}