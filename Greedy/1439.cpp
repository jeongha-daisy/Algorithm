#include <iostream>
#include <string>

using namespace std;

string s;
int count0;
int count1;

void solution()
{
    // 덩어리 개수 세기
    if (s[0] == '0')
        count0++;
    else
        count1++;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] != s[i])
        {
            if (s[i] == '0')
                count0++;
            else
                count1++;
        }
    }
    cout << min(count0, count1);
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    solution();
    return 0;
}