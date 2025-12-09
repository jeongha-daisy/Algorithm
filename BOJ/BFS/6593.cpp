#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;

char building[31][31][31] = {};
int minutes[31][31][31] = {};
int l, r, c;
queue<tuple<int, int, int>> q;
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void BFS()
{
    while (!q.empty())
    {
        int z = get<0>(q.front());
        int x = get<1>(q.front());
        int y = get<2>(q.front());

        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx >= 0 && nx < r && ny >= 0 && ny < c && nz >= 0 && nz < l)
            {
                if (building[nz][nx][ny] == 'E')
                {

                    cout << "Escaped in " << minutes[z][x][y] << " minute(s).\n";
                    return;
                }
                if (minutes[nz][nx][ny] == 0 && building[nz][nx][ny] == '.')
                {
                    minutes[nz][nx][ny] += minutes[z][x][y] + 1;
                    q.push(make_tuple(nz, nx, ny));
                }
            }
        }
    }
    cout << "Trapped!\n";
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        // 입력
        cin >> l >> r >> c;

        // 종료 조건
        if (l == 0 && r == 0 && c == 0)
            return 0;

        // 초기화
        memset(building, 0, sizeof(building));
        memset(minutes, 0, sizeof(minutes));
        while (!q.empty())
            q.pop();

        // 빌딩 정보
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    char c;
                    cin >> c;
                    if (c == 'S')
                    {
                        q.push(make_tuple(i, j, k));
                        minutes[i][j][k] = 1;
                    }
                    building[i][j][k] = c;
                }
            }
        }
        BFS();
    }
    return 0;
}