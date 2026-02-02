#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int answer;
pair<int, int> lines[1000001];

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
    // 시작 점 기준 정렬
    sort(lines, lines + n, compare);

    for (int i = 0; i < n; i++)
    {

        cout << lines[0].first << " " << lines[0].second << endl;
    }
    int startPoint = lines[0].first;
    int endPoint = lines[0].second;
    answer += endPoint - startPoint;

    for (int i = 1; i < n; i++)
    {
        int s = lines[i].first;
        int e = lines[i].second;

        // 현재 직선보다 더 긋는 경우
        if (s <= endPoint && e >= endPoint)
        {
            answer += e - endPoint;
            endPoint = e;
        }

        // 시작 지점이 현재 직선보다 밖에 있으면 새로 긋는 선
        else if (s >= endPoint)
        {
            startPoint = s;
            endPoint = e;
            answer += endPoint - startPoint;
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
        lines[i] = make_pair(a, b);
    }
    solution();
    return 0;
}