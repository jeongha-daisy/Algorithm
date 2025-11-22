#include <iostream>
#include <queue>
using namespace std;

int R, C;
char maze[1001][1001];
int f_maze[1001][1001];
int j_maze[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> f_q;
queue<pair<int, int>> j_q;

void f_BFS()
{
    while (!f_q.empty())
    {
        int x = f_q.front().first;
        int y = f_q.front().second;
        f_q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < R && ny >= 0 && ny < C)
            {
                if (f_maze[nx][ny] == 0 && maze[nx][ny] == '.')
                {
                    f_maze[nx][ny] = f_maze[x][y] + 1;
                    f_q.push(make_pair(nx, ny));
                }
            }
        }
    }
    /*
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cout << f_maze[i][j] << " ";
            }
            cout << endl;
        }
        */
}

int j_BFS()
{
    while (!j_q.empty())
    {
        int x = j_q.front().first;
        int y = j_q.front().second;
        j_q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < R && ny >= 0 && ny < C)
            {
                // f_maze[nx][ny] > j_maze[x][y] + 1
                if (j_maze[nx][ny] == 0 && maze[nx][ny] == '.')
                {
                    // 불이 이미 번졌고 (f_maze[nx][ny] != 0) 불이 번진 시점보다 더 뒤에 도착한 경우는 이동할 수 없다.
                    if (f_maze[nx][ny] != 0 && f_maze[nx][ny] <= j_maze[x][y] + 1)
                        continue;

                    j_maze[nx][ny] = j_maze[x][y] + 1;
                    j_q.push(make_pair(nx, ny));

                    if (nx == 0 || nx == R - 1 || ny == 0 || ny == C - 1)
                    {
                        return j_maze[nx][ny];
                    }
                }
            }
        }
    }
    /*
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cout << j_maze[i][j] << " ";
            }
            cout << endl;
        }
    */
    return 0;
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;

    int j_x, j_y;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char info;
            cin >> info;
            if (info == 'F')
            {
                maze[i][j] = info;
                f_q.push(make_pair(i, j));
                f_maze[i][j] = 1;
                j_maze[i][j] = 0;
                continue;
            }
            else if (info == 'J')
            {
                if (i == 0 || i == R - 1 || j == 0 || j == C - 1)
                {
                    cout << 1;
                    return 0;
                }
                maze[i][j] = info;
                j_q.push(make_pair(i, j));
                f_maze[i][j] = 0;
                j_maze[i][j] = 1;
            }
            else if (info == '.')
            {
                maze[i][j] = info;
                f_maze[i][j] = 0;
                j_maze[i][j] = 0;
            }
            else
            {
                maze[i][j] = info;
                f_maze[i][j] = -1;
                j_maze[i][j] = -1;
            }
        }
    }

    // 불 번지기
    f_BFS();

    // 지훈이 이동
    int result = j_BFS();
    if (!result)
        cout << "IMPOSSIBLE";
    else
    {
        cout << result;
    }

    return 0;
}