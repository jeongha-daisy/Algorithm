# Array

## [1021 회전하는 큐](https://www.acmicpc.net/problem/1021)

algorithm 라이브러리의 find와 distance를 활용하여 해당 타겟이 front에 가까운지 back에 가까운지 검사한다.
더 가까운 쪽으로 회전시킨다.

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
