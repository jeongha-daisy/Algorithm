
#include <iostream>
using namespace std;

void solution(int n)
{
    int number = 1;
    int m = 0;

    while (true)
    {
        if (to_string(number).find("666") != string::npos)
        {
            m++;
            if (m == n)
            {
                cout << number;
                return;
            }
        }
        number++;
    }
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    solution(n);
    return 0;
}