#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

char map[1001][1001];
int fire[1001][1001];
int sangguen[1001][1001];
pair<int, int> sangguen_loc;
queue<pair<int, int>> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<string> answers;
int testcase;

void BFS(int w, int h, bool isFire)
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
            if (nx >= 0 && nx < h && ny >= 0 && ny < w)
            {
                if (isFire)
                {
                    if (map[nx][ny] == '.' && fire[nx][ny] == 0)
                    {
                        q.push(make_pair(nx, ny));
                        fire[nx][ny] = fire[x][y] + 1;
                    }
                }
                else
                {
                    if (map[nx][ny] == '.' && sangguen[nx][ny] == 0 && (fire[nx][ny] > sangguen[x][y] + 1 || fire[nx][ny] == 0))
                    {
                        sangguen[nx][ny] = sangguen[x][y] + 1;
                        if (nx == 0 || ny == 0 || nx == h - 1 || ny == w - 1)
                        {
                            answers.push_back(to_string(sangguen[nx][ny]));
                            return;
                        }
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
    if (!isFire)
        answers.push_back("IMPOSSIBLE");
}

void BFS_sg(int w, int h)
{
}

void solution()
{
    while (testcase--)
    {
        int w, h;
        cin >> w >> h;

        // 초기화
        memset(fire, 0, sizeof(fire));
        memset(sangguen, 0, sizeof(sangguen));
        while (!q.empty())
            q.pop();

        // 입력
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                char c;
                cin >> c;
                map[i][j] = c;
                if (map[i][j] == '*')
                {
                    q.push(make_pair(i, j));
                    fire[i][j] = 1;
                }
                else if (map[i][j] == '@')
                {
                    sangguen_loc = make_pair(i, j);
                    sangguen[i][j] = 1;
                }
            }
        }
        if (sangguen_loc.first == 0 || sangguen_loc.second == 0 || sangguen_loc.first == h - 1 || sangguen_loc.second == w - 1)
        {
            answers.push_back("1");
            continue;
        }

        // 불 번짐
        BFS(w, h, true);
        // 상근이 이동
        q.push(sangguen_loc);
        BFS(w, h, false);
    }

    for (string s : answers)
        cout << s << endl;
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