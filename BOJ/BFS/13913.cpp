#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define MAX 100001
#define MIN 0
pair<int, int> map[MAX];
bool visited[MAX];
queue<int> q;
stack<int> answer;

void solution(int n, int k)
{
    if (n == k)
    {
        cout << 0;
        return;
    }
    q.push(n);
    visited[n] = true;
    map[n].first = 0;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        if (!visited[a - 1] && a - 1 < MAX && a - 1 >= MIN)
        {
            q.push(a - 1);
            map[a - 1].first += map[a].first + 1;
            map[a - 1].second = a;
            visited[a - 1] = true;
            if (a - 1 == k)
            {
                cout << map[a - 1].first << endl;
                int l = map[a - 1].second;
                while (l != n)
                {
                    answer.push(l);
                    l = map[l].second;
                }
                cout << n << " ";
                while (!answer.empty())
                {
                    cout << answer.top() << " ";
                    answer.pop();
                }
                cout << k;
                return;
            }
        }

        if (!visited[a + 1] && a + 1 < MAX && a + 1 >= MIN)
        {
            q.push(a + 1);
            map[a + 1].first += map[a].first + 1;
            map[a + 1].second = a;
            visited[a + 1] = true;
            if (a + 1 == k)
            {
                cout << map[a + 1].first << endl;
                int l = map[a + 1].second;
                while (l != n)
                {
                    answer.push(l);
                    l = map[l].second;
                }
                cout << n << " ";
                while (!answer.empty())
                {
                    cout << answer.top() << " ";
                    answer.pop();
                }
                cout << k;
                return;
            }
        }

        if (!visited[2 * a] && 2 * a < MAX && 2 * a >= MIN)
        {
            q.push(2 * a);
            map[2 * a].first += map[a].first + 1;
            map[2 * a].second = a;
            visited[2 * a] = true;
            if (2 * a == k)
            {
                cout << map[2 * a].first << endl;
                int l = map[2 * a].second;
                while (l != n)
                {
                    answer.push(l);
                    l = map[l].second;
                }
                cout << n << " ";
                while (!answer.empty())
                {
                    cout << answer.top() << " ";
                    answer.pop();
                }
                cout << k;
                return;
            }
        }
    }
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    solution(N, K);
    return 0;
}