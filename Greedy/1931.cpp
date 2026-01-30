#include <iostream>
#include <algorithm>
using namespace std;

int n;
int answer = 1;
pair<int, int> meetingTime[100001];

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
    {
        return true;
    }
    else if (a.second == b.second)
    {
        return a.first < b.first;
    }
    else
        return false;
}

void solution()
{
    // 끝나는 시간 기준 정렬
    sort(meetingTime, meetingTime + n, compare);

    int closeAt = meetingTime[0].second;
    for (int i = 1; i < n; i++)
    {
        if (closeAt <= meetingTime[i].first)
        {
            closeAt = meetingTime[i].second;
            answer++;
        }
    }
    cout << answer;
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        meetingTime[i] = make_pair(a, b);
    }
    solution();
    return 0;
}