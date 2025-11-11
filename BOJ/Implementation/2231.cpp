#include <iostream>
#include <string>
using namespace std;

void solution(int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int m = n - i;
        int sum = 0;
        for (int j = 0; j < to_string(m).size(); j++)
        {
            sum += to_string(m)[j] - 48;
        }
        if (m + sum == n)
        {
            if (result == 0)
                result = m;
            else
                result = min(m, result);
        }
    }

    cout << result;
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