#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1000
int n;
int graph[100000][3];
int cost[100000][3];
int solution()
{
    cost[0][0] = MAX;
    cost[0][1] = graph[0][1];
    cost[0][2] = graph[0][2] + graph[0][1];

    for (int i = 1; i < n; i++)
    {
        cost[i][0] = min(cost[i - 1][0], cost[i - 1][1]) + graph[i][0];

        cost[i][1] = min({cost[i - 1][0], cost[i - 1][1], cost[i - 1][2], cost[i][0]}) + graph[i][1];

        cost[i][2] = min({cost[i - 1][1], cost[i - 1][2], cost[i][1]}) + graph[i][2];
    }

    return cost[n - 1][1];
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    while (true)
    {
        cin >> n;
        if (n == 0)
            return 0;
        for (int i = 0; i < n; i++)
            cin >> graph[i][0] >> graph[i][1] >> graph[i][2];

        cout << tc << ". " << solution() << "\n";
        tc++;
    }

    return 0;
}