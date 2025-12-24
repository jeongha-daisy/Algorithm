#include <iostream>
using namespace std;

int n;
long int ways[1001];
void solution()
{
    /*

    2 * 1을 채우는 법은
        세로 타일 하나

    2 * 2를 채우는 법은
        2 * 1에다가 세로 타일 하나 추가하는 법
        가로 타일 두개로 2 * 2 모양 만들기
        정사각형 한개로 2 * 2 모양 만들기           => 3

    2 * 3을 채우는 법은
        2 * 2에다가 세로 타일 하나 추가하는 법 (3)
        2 * 1에다가 가로타일 만들기 + 정사각형 만들기 (1*2)   => 5

    2 * 4를 채우는 법은
        2 * 3에다가 세로 타일 하나 추가하는 법
        2 * 2에다가 가로타일 만들기 + 정사각형 만들기   => 9

    */

    ways[1] = 1;
    ways[2] = 3;
    for (int i = 3; i < n + 1; i++)
    {
        ways[i] = (ways[i - 1] + ways[i - 2] * 2) % 10007;
    }
    cout << ways[n];
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solution();
    return 0;
}