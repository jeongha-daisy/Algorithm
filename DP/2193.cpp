#include <iostream>
using namespace std;

#define MAX 90

int n;
long int arr[MAX + 1];

void solution()
{
    arr[1] = 1;
    arr[2] = 1;
    for (int i = 3; i < n + 1; i++)
    {
        arr[i] = arr[i - 2] + arr[i - 1];
    }
    cout << arr[n];
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