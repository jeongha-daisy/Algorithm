#include <iostream>
using namespace std;

int stairs[301]; // 각 계단의 싱글 점수
int answer[301]; // 각 계단의 토탈 점수
int n;

int solution()
{
    // 계단이 한 개인 경우
    if (n == 1)
        return stairs[0];

    // 계단이 두 개인 경우
    if (n == 2)
        return stairs[0] + stairs[1];

    // 계단이 세 개인 경우
    if (n == 3)
        return max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

    // 초기 값
    answer[0] = stairs[0];
    answer[1] = stairs[0] + stairs[1];
    answer[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

    for (int i = 3; i < n; i++)
    {
        answer[i] = max(answer[i - 2] + stairs[i], answer[i - 3] + stairs[i - 1] + stairs[i]);
    }

    return answer[n - 1];
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        stairs[i] = a;
    }

    cout << solution();
    return 0;
}