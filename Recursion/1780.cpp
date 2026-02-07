#include <iostream>
using namespace std;

int n;
int paper[2188][2188];
int answer[3]; // -1, 0, 1 (0, 1, 2)

bool check(int x, int y, int n)
{
    int firstValue = paper[x][y];
    for (int a = x; a < x + n; a++)
    {
        for (int b = y; b < y + n; b++)
        {
            if (a == x && b == y)
                continue;

            // 다른 숫자를 발견했다면
            if (paper[a][b] != firstValue)
                return false;
        }
    }
    return true;
}

void recursion(int x, int y, int z)
{
    // 모두 같은 숫자로 되어있는지 확인
    if (check(x, y, z))
    {
        // 같은 숫자로 된 종이라면 종이 개수 추가
        answer[paper[x][y] + 1] += 1;
    }
    else
    {
        // 다른 숫자로 되어 있다면 쪼개서 재탐색
        int n = z / 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                recursion(x + i * n, y + j * n, n);
            }
        }
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
        for (int j = 0; j < n; j++)
        {
            cin >> paper[i][j];
        }
    }

    recursion(0, 0, n);

    for (int i = 0; i < 3; i++)
        cout << answer[i] << endl;
    return 0;
}