#include <iostream>
#include <string>
#include <list>
using namespace std;

void solution(int N){
    list<string> ans;
    for(int i =0; i < N; i++){
        string inputStr;
        cin >> inputStr;

        list<char> str;
        list<char>::iterator it = str.begin();

        for(int i = 0; i < inputStr.length(); i++){
            switch(inputStr[i]){
                case '<':
                    // 왼쪽으로 커서 이동
                    if(it != str.begin()){
                        it--;
                    }
                    break;
                case '>':
                    // 오른쪽으로 커서 이동
                    if(it != str.end()){
                        it++;
                    }
                    break;
                case '-':
                    // 백스페이스
                    if(it != str.begin()){
                        it = str.erase(--it);
                    }
                    break;
                default:
                    str.insert(it, inputStr[i]);
                    break;
            }
        }
        string s(str.begin(), str.end());
        ans.push_back(s);
    }

    for (list<string>::iterator it = ans.begin(); it != ans.end(); it++){
        cout << *it << endl;
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