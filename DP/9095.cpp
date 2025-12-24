#include <iostream>
using namespace std;

int D[11] = {
    0,
};

void DP()
{
    D[1] = 1;
    D[2] = 2;
    D[3] = 4;

    for (int i = 4; i < 11; i++)
        D[i] = D[i - 1] + D[i - 2] + D[i - 3];
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    DP();

    while (T--)
    {
        int a;
        cin >> a;
        cout << D[a] << endl;
    }
    return 0;
}