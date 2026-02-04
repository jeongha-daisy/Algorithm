#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/*
우선순위 큐 레퍼런스 참고
https://en.cppreference.com/w/cpp/container/priority_queue.html
*/

int n;
int answer = 1;
pair<int, int> meetingTime[200001];

struct customLess
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, customLess> classRooms;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
    {
        return true;
    }
    else if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
        return false;
}

void solution()
{
    // 끝나는 시간 기준 정렬
    sort(meetingTime, meetingTime + n, compare);
    classRooms.push(meetingTime[0]);

    int closeAt;
    for (int i = 1; i < n; i++)
    {
        // 탐색하지 않고, 우선순위 큐로 선택
        closeAt = classRooms.top().second;

        // 끝나는 시간이 현 미팅 시작시간보다 짧으면
        if (closeAt <= meetingTime[i].first)
        {
            classRooms.pop();
        }
        classRooms.push(meetingTime[i]);
    }
    cout << classRooms.size() << "\n";
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