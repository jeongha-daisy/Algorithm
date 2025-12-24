#include <iostream>
using namespace std;

long int P[101];
int n;
int t;
void solution()
{
    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    P[4] = 2;
    P[5] = 2;
    P[6] = 3;
    P[7] = 4;
    P[8] = 5;
    P[9] = 7;
    P[10] = 9;

    for (int i = 11; i < 101; i++)
    {
        P[i] = P[i - 5] + P[i - 1];
    }
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    solution();
    while (t--)
    {
        int a;
        cin >> a;
        cout << P[a] << endl;
    }

    return 0;
}