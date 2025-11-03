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

## [6198 옥상 정원 꾸미기](https://www.acmicpc.net/problem/6198)

N의 최대값은 80,000이다. 80,000개의 빌딩이 있고 1번 빌딩의 높이 80,000, 2번 빌딩의 높이는 79,999, 3번 빌딩의 높이는 .... 이 있을 때 이 테스트 케이스의 경우 1부터 79,999까지 등차수열의 합이 답이다. 그렇다면 int 자료형의 범위를 훨씬 넘어가므로 sum의 자료형은 long int여야한다.

A건물에서 B건물이 보인다면 B건물에서 보이는 건물들도 보일 것이므로 벤치마킹 가능한 건물을 저장할 저장공간을 만들어 참조한다.

    while(!stk.empty()){
            int front_height = buildings[stk.top()];
            if(front_height >= buildings[idx]){
                break;
            }
            else{
                front_buildings[idx] += front_buildings[stk.top()] + 1;
                stk.pop();
            }
        }
        stk.push(idx);

## [4949 균형잡힌 세상](https://www.acmicpc.net/problem/4949)

getline()함수로 문자열을 한 번에 입력받는다. 입력받은 문자열을 문자 하나씩 탐색하며 조건에 맞게 출력한다. 괄호쌍을 스택으로 검사해 열린 괄호와 닫힌 괄호가 쌍을 이룰 수 있도록 한다.
