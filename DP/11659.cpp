#include <iostream>
#include <vector>
using namespace std;

#define MAX 100000
int n, m;
int numbers[MAX + 1];
int sums[MAX + 1];
vector<int> answers;

void solution()
{
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        answers.push_back(sums[b] - sums[a - 1]);
    }

    for (int answer : answers)
        cout << answer << "\n";
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int sum = 0;
    sums[0] = sum;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> numbers[i];
        sum += numbers[i];
        sums[i] = sum;
    }

    solution();
    return 0;
}