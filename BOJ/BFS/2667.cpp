#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int map[26][26];
bool visited[26][26];
queue<pair<int, int>> q;
vector<int> answer;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;

int BFS(int n)
{
    int count = 1;
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
                if (!visited[nx][ny] && map[nx][ny] == 1)
                {
                    count++;
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return count;
}

void solution()
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && map[i][j] == 1)
            {
                count++;
                q.push(make_pair(i, j));
                visited[i][j] = true;
                answer.push_back(BFS(n));
            }
        }
    }
    cout << count << "\n";

    for (int a : answer)
    {
        cout << a << "\n";
    }
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            map[i][j] = s[j] - 48;
        }
    }
    solution();
    return 0;
}