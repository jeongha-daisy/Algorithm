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

    string str;
    getline(cin, str);

## [10799 쇠막대기](https://www.acmicpc.net/problem/10799)

previous_bracket으로 바로 전 bracket의 모양을 저장한다.
열린 괄호가 나올 때마다 새로운 스틱이 추가된 것으로 보고 current_stick의 값을 하나 올린다.
닫힌 괄호가 나오고 바로 전 괄호가 열린 괄호였다면 레이저이므로 추가했던 스틱을 취소하고, 현재 스틱들을 자른다고 가정, total_sticks에 현재 스틱만큼 값을 추가한다.
닫힌 괄호가 나오고 바로 전 괄호가 열린 괄호가 아니라면 스틱이 끝났다는 뜻이므로 current_stick의 값을 하나 줄이고 total_sticks에 하나를 추가한다.

## [2504 괄호의 값](https://www.acmicpc.net/problem/2504)

스택에 괄호의 모양과 자식 괄호의 점수를 저장한다. 열린 괄호가 들어올 때는 점수 0과 함께 push 연산만 수행하고, 닫힌 괄호가 들어왔을 때 조건에 맞는 연산을 한다. 기본적으로 pop을 두 번 수행해 내 바깥 괄호의 점수값을 갱신하여 다시 스택에 넣는다.

    else if (bracket == ')')
        {
            // 스택이 비었거나 괄호 짝이 맞지 않는 경우 올바르지 못한 괄호열이므로 0을 출력
            if (stk.empty() || stk.top().first == '[')
                return 0;

            // 짝꿍이 되는 열린 괄호를 현재 괄호로 본다.
            pair<char, int> my_bracket = stk.top();
            stk.pop();

            // pop 수행 후 스택이 비었다면 바깥을 감싸는 바깥 괄호가 더이상 없는 것이다.
            if (stk.empty())
            {
                // 내부 괄호의 숫자 * 2를 저장한다. 값이 0이라면 내부 괄호가 없는 것이므로 2를 저장한다.
                if(my_bracket.second == 0)
                    ans += 2;
                ans += my_bracket.second * 2;
                continue;
            }

            // pop 수행 후 스택이 비어있지 않다면 바깥을 감싸는 바깥 괄호가 있다.
            pair<char, int> exterior_bracket = stk.top();
            stk.pop();

            // 현재 내 괄호의 점수 값이 0이면 내부 괄호가 없는 것이다.
            if (my_bracket.second == 0)
            {
                // 바깥 괄호에 2점만 추가한다.
                exterior_bracket.second += 2;
            }
            else
            {
                // 내 괄호의 점수 값이 0이 아니면 내부 괄호가 있는 것이므로 내 점수 값에 2를 곱해 바깥 괄호의 점수 값에 저장한다.
                exterior_bracket.second += my_bracket.second * 2;
            }

            // 갱신된 바깥 괄호를 다시 스택에 추가한다.
            stk.push(exterior_bracket);
        }
