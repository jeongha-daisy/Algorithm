#include <iostream>
using namespace std;

#define DIVISOR 10007
int n;
int numbers[1001][10]; // [n][m] 길이가 n인 수 중 m으로 시작하는 오르막수
int solution()
{
    // 한자리 오르막수의 총 개수
    int count = 10;

    if (n == 1)
        return count;

    // 한자리 수 중 j로 시작하는 오르막수는 무조건 한 개
    for (int j = 0; j < 10; j++)
    {
        numbers[1][j] = 1;
    }

    int new_count = 0;
    for (int i = 2; i <= n; i++)
    {
        // count i-1자리 오르막수의 총 개수.
        // 0이 맨 앞에 있는 경우는 항상 오르막수 조건 성립하므로 i-1자리 모든 오르막수 가능
        numbers[i][0] = count % DIVISOR;

        // 새로 총 합을 구할 변수
        new_count = numbers[i][0];
        for (int j = 1; j < 10; j++)
        {
            // i-1자리 오르막수에서 j-1로 시작하는 수는 오르막수가 될 수 없다.
            count -= numbers[i - 1][j - 1];
            numbers[i][j] = count % DIVISOR;
            new_count += (numbers[i][j] % DIVISOR);
        }
        count = new_count;
    }

    return new_count % DIVISOR;
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cout << solution();
    return 0;
}