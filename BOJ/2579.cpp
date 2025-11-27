#include <iostream>
#include <vector>

using namespace std;

vector<int> stairs;
vector<int> answer;
int n;

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
        stairs.push_back(a);
    }

    answer.push_back(stairs[0]);
    if (n == 1)
    {
        cout << answer[0];
        return 0;
    }
    // 계단이 두 개일 때
    answer[1] = stairs[0] + stairs[1];
    if (n == 2)
    {
        cout << answer[1];
        return 0;
    }

    // 계단이 세 개일 때
    answer[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

    // ex.네 번째 계단은 1, 2, 4 혹은 1, 3, 4 중 최대 값
    for (int i = 3; i < n; i++)
    {
        cout << max(answer[i - 2] + stairs[i], answer[i - 3] + stairs[i - 1] + stairs[i]);
        answer[i] = max(answer[i - 2] + stairs[i], answer[i - 3] + stairs[i - 1] + stairs[i]);
    }

    cout << answer[n - 1];

    return 0;
}