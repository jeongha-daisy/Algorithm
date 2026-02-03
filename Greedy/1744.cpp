#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long int sum;
vector<int> pos;
vector<int> neg;

bool compare(int a, int b)
{
    return a > b;
}

void solution()
{
    // 정렬
    sort(pos.begin(), pos.end(), compare);
    sort(neg.begin(), neg.end());

    // 양수는 큰수 순서대로 두 개씩 곱하기
    for (int i = 0; i < pos.size(); i += 2)
    {
        // 다음 수가 1이거나 현재 인덱스가 마지막이면, 묶지 않는 것이 유리하다.
        if (i == pos.size() - 1 || pos[i + 1] == 1 || pos[i] <= 1)
        {
            sum += pos[i];
            i--;
        }
        else
            sum += (long long)pos[i] * pos[i + 1];
    }

    // 음수는 음수는 작은수 순서대로 두 개씩 곱하기
    for (int i = 0; i < neg.size(); i++)
    {
        // 마지막 요소인 경우 그냥 더함
        if (i == neg.size() - 1)
        {
            sum += neg[i];
        }
        else
        {
            sum += (long long)neg[i] * neg[i + 1];
            i++;
        }
    }

    cout << sum;
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a > 0)
            pos.push_back(a);
        else
            neg.push_back(a);
    }
    solution();
    return 0;
}