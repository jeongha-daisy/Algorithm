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

## [5430 AC](https://www.acmicpc.net/problem/5430)

주어진 숫자 배열을 [와 ]를 제외한 string으로 받아 ,를 기준으로 split하여 deque에 저장한다. 뒤집기가 나오면 매번 reverse를 수행할 필요 없이 deque의 특징을 이용해 접근하는 방향만 바꾼다. 방향을 기준으로 forward가 true면 pop_front()를 수행하고 false면 pop_back()을 수행한다.

        deque<int> strToVector(string str)
        {
            deque<int> numbers;
            string clean_str = str.substr(1, str.length() - 2);
            stringstream ss(clean_str);
            string token;
            while (getline(ss, token, ','))
            {
                if (!token.empty())
                {
                    numbers.push_back(stoi(token));
                }
            }
            return numbers;
        }

---

        if (ts.functions[j] == 'R')
                // 뒤집기
                forward = !forward;
