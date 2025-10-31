#include <iostream>
#include <string>
#include <deque>
using namespace std;
void solution(int N){
    deque<int> q;

    for (int i = 0; i < N; i++){
        string cmd;
        cin >> cmd;

        if(cmd == "push_front")
        {
            int number;
            cin >> number;
            q.push_front(number);
            
        } 
        else if(cmd == "push_back")
        {
            int number;
            cin >> number;
            q.push_back(number);
            
        } 
        else if(cmd == "pop_front")
        {
            if(!q.empty())
            {
                cout << q.front() << endl;
                q.pop_front();
            }
            else 
            {
                cout << -1 << endl;
            }
        } 
        else if(cmd == "pop_back")
        {
            if(!q.empty())
            {
                cout << q.back() << endl;
                q.pop_back();
            }
            else 
            {
                cout << -1 << endl;
            }
        } 
        else if(cmd == "front")
        {
            if(!q.empty())
            {
                cout << q.front() << endl;
            }
            else 
            {
                cout << -1 << endl;
            }
        } 
        else if(cmd == "back")
        {
            if(!q.empty())
            {
                cout << q.back() << endl;
            }
            else 
            {
                cout << -1 << endl;
            }
        } 
        else if(cmd == "size")
        {
            cout << q.size() << endl;
        } 
        else if(cmd == "empty")
        {
            if(q.empty())
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