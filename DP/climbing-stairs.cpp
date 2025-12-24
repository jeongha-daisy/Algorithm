#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n)
{
    int stairs[46] = {
        0,
    };

    stairs[1] = 1;
    stairs[2] = 2;

    for (int i = 3; i < 46; i++)
    {
        stairs[i] = stairs[i - 2] + stairs[i - 1];
    }

    return stairs[n];
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    cout << climbStairs(n);
    return 0;
}