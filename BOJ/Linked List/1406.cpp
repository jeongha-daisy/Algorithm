#include <iostream>
#include <list>
#include <string>

using namespace std;

void solution(string initialStr, int M){
    list<char> str;
    list<char>::iterator cursor;
    for(int i = 0; i < initialStr.length(); i++){
        str.push_back(initialStr[i]);
    }

    cursor = str.end();

    for(int i = 0; i < M; i++){
        char command;
        cin >> command;

        switch(command){
            case 'L':
                if(cursor != str.begin())
                    cursor--;
                break;
            case 'D':
                if(cursor != str.end())
                    cursor++;
                break;
            case 'B':
                if(cursor != str.begin())
                    cursor = str.erase(--cursor);
                break;
            case 'P':
                char character;
                cin >> character;
                str.insert(cursor, character);
                break;
            default:
                break;
        }
    }

    for(list<char>::iterator t = str.begin(); t != str.end(); t++)
        cout << *t;
}

int main(){
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    string initialStr;
    cin >> initialStr;

    int M;
    cin >> M;

    solution(initialStr, M);
    return 0;
}