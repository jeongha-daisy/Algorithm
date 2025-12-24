#include <iostream>
#include <string>
#include <deque>

using namespace std;
void solution(int N){
    deque<int> q;

    for (int i = 0; i < N; i++){
        string cmd;
        cin >> cmd;

        if(cmd == "push")
        {
            int number;
            cin >> number;
            q.push_back(number);
            
        } 
        else if(cmd == "pop")
        {
            if(!q.empty())
            {
                cout << q.front() << "\n";
                q.pop_front();
            }
            else 
            {
                cout << -1 << "\n";
            }
        } 
        else if(cmd == "size")
        {
            cout << q.size() << "\n";
        } 
        else if(cmd == "empty")
        {
            if(q.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        } 
        else if(cmd == "front")
        {
            if(!q.empty())
            {
                cout << q.front() << "\n";
            }
            else 
            {
                cout << -1 << "\n";
            }
        } 
        else if(cmd == "back")
        {
            if(!q.empty())
            {
                cout << q.back() << "\n";
            }
            else 
            {
                cout << -1 << "\n";
            }
        } 
        
        else {}

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