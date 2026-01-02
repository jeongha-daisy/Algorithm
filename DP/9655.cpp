#include <iostream>
using namespace std;

int N;
int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    if (N % 2 == 1)
        cout << "SK\n";
    else
        cout << "CY\n";
    return 0;
}
