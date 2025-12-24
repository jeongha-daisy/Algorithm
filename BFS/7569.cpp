#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

// 전역 변수
int box[101][101][101] = {};
int n, m, h;
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

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && nz >= 0 && nz < h)
            {
                if (box[nz][nx][ny] == 0)
                {
                    box[nz][nx][ny] = box[z][x][y] + 1;
                    q.push(make_tuple(nz, nx, ny));
                }
            }
        }
    }
}

void solution(int n, int m)
{

    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (box[k][i][j] == 1)
                {
                    q.push(make_tuple(k, i, j));
                }
            }
        }
    }
    BFS();

    int longgest = 0;
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (box[k][i][j] == 0)
                {
                    cout << -1;
                    return;
                }
                longgest = max(longgest, box[k][i][j]);
            }
        }
    }
    cout << longgest - 1;
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;

    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int info;
                cin >> info;
                box[k][i][j] = info;
            }
        }
    }
    solution(n, m);
    return 0;
}