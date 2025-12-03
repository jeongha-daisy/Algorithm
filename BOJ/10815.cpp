#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> myCards;
vector<int> givenCards;
vector<int> results;

int binary_search(int card, int startIndex, int endIndex)
{
    if (startIndex >= endIndex)
        return 0;

    int start = myCards[startIndex];
    int end = myCards[endIndex];
    int midIndex = (endIndex + startIndex) / 2;
    int mid = myCards[midIndex];

    // 시작, 중간, 끝 값이 찾아야할 카드라면 1 반환 후 종료
    if (start == card or end == card or mid == card)
        return 1;

    if (card > mid)
        return binary_search(card, midIndex + 1, endIndex);
    else
        return binary_search(card, startIndex, midIndex - 1);
}
void solution(int n, int m)
{
    // 주어진 카드 하나씩 탐색
    for (int i = 0; i < m; i++)
    {
        int result = binary_search(givenCards[i], 0, n - 1);
        results.push_back(result);
    }

    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << " ";
    }
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 상근이 카드
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        myCards.push_back(a);
    }

    // 정렬
    sort(myCards.begin(), myCards.end());

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        givenCards.push_back(a);
    }

    solution(n, m);
    return 0;
}