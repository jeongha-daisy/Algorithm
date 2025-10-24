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
