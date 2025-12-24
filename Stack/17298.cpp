#include <iostream>
#include <stack>

using namespace std;

void solution(int N){
    stack<int> NGE;
    stack<int> data_stack;
    stack<int> comparison_stack;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        data_stack.push(a);
    }
    if(N == 1){
        cout << -1;
        return ;
    }


    // 맨 오른쪽 숫자는 오큰수가 없다.
    NGE.push(-1);
    comparison_stack.push(data_stack.top());
    data_stack.pop();

    //맨 오른쪽에서 두 번째 숫자는 맨 오른쪽 숫자에만 달려있다.
    if(data_stack.top() < comparison_stack.top()){
        NGE.push(comparison_stack.top());
    }
    else{
        NGE.push(-1);
    }
    comparison_stack.push(data_stack.top());
    data_stack.pop();

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

    while(!NGE.empty()){
        cout << NGE.top() << " ";
        NGE.pop();
    }
}

int main(){
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    solution(N);
    return 0;
}