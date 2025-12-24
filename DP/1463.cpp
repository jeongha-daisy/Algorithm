#include <iostream>
using namespace std;

int arr[1000001];
int n;

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    arr[1] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (i == 1)
            continue;

        int value = arr[i - 1] + 1;

        if (i % 2 == 0)
            value = min(value, arr[i / 2] + 1);

        if (i % 3 == 0)
            value = min(value, arr[i / 3] + 1);

        arr[i] = value;
    }
    cout << arr[n];
    return 0;
}