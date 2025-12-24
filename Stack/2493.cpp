#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

void solution(int N, vector<int> tops){

    stack<int> temp;
    string ans;
    for (int i = 0; i < N; i++){

        if(i == 0){
            ans += "0 ";
            temp.push(i + 1);
            continue;
        }
        
        while(true){
            if(temp.empty()){
                ans += "0 ";
                temp.push(i + 1);
                break;
            }
            if(tops[temp.top() - 1] > tops[i]){
                ans += to_string(temp.top());
                ans += ' ';
                temp.push(i + 1);
                break;
            }
            else{
                temp.pop();
            }

        }
    }
    cout << ans;
}

int main(){
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    vector<int> tops;

    cin >> N;
    for (int i = 0; i < N; i ++){
        int a;
        cin >> a;
        tops.push_back(a);
    }
    solution(N, tops);
    return 0;
}