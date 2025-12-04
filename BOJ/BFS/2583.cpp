#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 101
#define MIN 0

int M, N, K;
int map[MAX][MAX] = {
    0,
};
bool visited[MAX][MAX];
queue<pair<int, int>> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<int> answer_size;
int answer = 0;

int BFS(int i, int j)
{
    q.push(make_pair(i, j));
    visited[i][j] = true;
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

            if (nx >= 0 && nx < M && ny >= 0 && ny < N)
            {
                if (!visited[nx][ny] && map[nx][ny] == 0)
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
    // 그림 입력
    for (int i = 0; i < K; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int j = a; j < c; j++)
        {
            for (int k = b; k < d; k++)
            {
                map[k][j] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && map[i][j] == 0)
            {
                answer++;
                answer_size.push_back(BFS(i, j));
            }
        }
    }

    cout << answer << endl;
    sort(answer_size.begin(), answer_size.end());
    for (int a : answer_size)
    {
        cout << a << " ";
    }
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N >> K;

    solution();
    return 0;
}