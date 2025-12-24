#include <iostream>
#include <stack>
using namespace std;

void solution(int K){
    stack<int> stk;

    for(int i = 0; i < K; i++){
        int n;
        cin >> n;

        switch(n){
            case 0:
                stk.pop();
                break;
            default:
                stk.push(n);
                break;
        }
    }

    int sum = 0;
    while(!stk.empty()){
        sum += stk.top();
        stk.pop();
    }

    cout << sum;
}

int main(){
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int K;
    cin >> K;

    solution(K);
    return 0;
}