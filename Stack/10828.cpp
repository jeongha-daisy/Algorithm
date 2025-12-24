#include <iostream>
#include <string>
#include <stack>
using namespace std;
void solution(int N){
    stack<int> stk;

    for (int i = 0; i < N; i++){
        string cmd;
        cin >> cmd;

        if(cmd == "push")
        {
            int number;
            cin >> number;
            stk.push(number);
            
        } 
        else if(cmd == "pop")
        {
            if(!stk.empty())
            {
                cout << stk.top() << endl;
                stk.pop();
            }
            else 
            {
                cout << -1 << endl;
            }
        } 
        else if(cmd == "top")
        {
            if(!stk.empty())
            {
                cout << stk.top() << endl;
            }
            else 
            {
                cout << -1 << endl;
            }
        } 
        else if(cmd == "size")
        {
            cout << stk.size() << endl;
        } 
        else if(cmd == "empty")
        {
            if(stk.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        } else {}

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