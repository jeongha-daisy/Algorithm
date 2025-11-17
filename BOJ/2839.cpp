#include <iostream>
using namespace std;

int bags[5001] = {};

void solution()
{
    int n;
    cin >> n;
    bags[3] = 1;
    bags[5] = 1;
    bags[6] = 2;
    bags[8] = 2;
    bags[9] = 3;
    bags[10] = 2;
    bags[11] = 3;
    bags[12] = 4;

    for (int i = 13; i < n + 1; i++)
        bags[i] = bags[i - 5] + 1;

    if (bags[n] == 0)
        cout << -1;
    else
        cout << bags[n];
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
    return 0;
}