# Stack

## [17298 오큰수](https://www.acmicpc.net/problem/17298)

stack으로 숫자를 저장해 값을 비교한다. 입력 받은 데이터 숫자의 오른쪽에서부터 비교한다.
comparison_stack의 top값과 현재 데이터 값을 비교해 오큰수를 구한다.

    while(!data_stack.empty()){
        while(true)
        {
            if(comparison_stack.empty()){
                NGE.push(-1);
                break;
            }

            if(data_stack.top() >= comparison_stack.top())
            {
                comparison_stack.pop();
            }
            else
            {
                NGE.push(comparison_stack.top());
                break;
            }
        }
        comparison_stack.push(data_stack.top());
        data_stack.pop();
    }

## [1874 스택 수열](https://www.acmicpc.net/problem/1874)

받은 수열을 담을 스택, 빈 스택 두 공간에 차례로 push와 pop을 수행하며 역순의 수열을 구할 수 있는지 검사한다.
cur에 N부터 1까지 내려가면서 숫자를 세고, 받은 수열을 다 검사 했는데(data.empty()) cur이 1까지 내려가지 못했다면, 역순의 수열을 구하지 못한 것이므로 NO를 출력한다.
char을 담은 stack 출력시 stack을 비울 때마다 cout으로 출력하는 것보다 string에 저장해두고 한 번에 출력하는 것이 시간 효율이 좋다.
