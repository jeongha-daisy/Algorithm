#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

bool check_location(deque<int> deq, int target)
{

    deque<int>::iterator it = find(deq.begin(), deq.end(), target);

    // front까지의 거리
    int dist_front = distance(deq.begin(), it);
    // back까지의 거리
    int dist_back = distance(it, deq.end());

    if (dist_front >= dist_back)
        return true;
    else
        return false;
}

void solution(int N, int M, vector<int> numbers)
{
    deque<int> deq;
    int left_move = 0;
    int right_move = 0;

    for (int number = 1; number <= N; number++)
        deq.push_back(number);

    for (int i = 0; i < M; i++)
    {
        int target = numbers[i];
        // cout << ">> target: " << target << endl;
        if (deq.front() == target)
        {
            // cout << "  " << target << " founded\n";
            deq.pop_front();
            continue;
        }

        // back에 가까우면
        if (check_location(deq, target))
        {
            while (deq.front() != target)
            {
                // 3번 수행
                // cout << "  right move +1\n";
                int temp = deq.back();
                deq.pop_back();
                deq.push_front(temp);
                right_move++;
            }
            // cout << "  " << target << " founded\n";
            deq.pop_front();
        }
        // front에 가까우면
        else
        {
            while (deq.front() != target)
            {
                // 2번 수행
                // cout << "  left move +1\n";
                int temp = deq.front();
                deq.pop_front();
                deq.push_back(temp);
                left_move++;
            }
            // cout << "  " << target << " founded\n";
            deq.pop_front();
        }
    }
    cout << left_move + right_move;
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<int> numbers;
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        numbers.push_back(a);
    }

    solution(N, M, numbers);
    return 0;
}