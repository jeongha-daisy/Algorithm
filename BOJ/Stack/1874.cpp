#include <iostream>
#include <stack>
using namespace std;

void solution(int N){
    stack<int> data;
    for(int i=0; i< N; i++){
        int a;
        cin >> a;
        data.push(a);
    }
    int cur = N;
    
    stack<int> temp;
    stack<char> ans;

    bool isPossible = true;
    while (!data.empty())
    {
        if(data.top() == cur){
            ans.push('-');
            ans.push('+');
            data.pop();
            cur--;
            while (!temp.empty() && cur == temp.top()){
                ans.push('+');   
                cur --;
                temp.pop();
            }
        }
        else{
            temp.push(data.top());
            data.pop();
            ans.push('-');
        }
        
        if(cur > 0 && data.empty()){
            isPossible = false;
            break;
        }
    }

    if(isPossible){
        string output;
        while(!ans.empty()){
            output += ans.top();
            output += '\n';
            ans.pop();
        }
        cout << output;
    }
    else {
        cout << "NO";
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