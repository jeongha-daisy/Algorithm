#include <iostream>
#include <deque>
using namespace std;

void solution(int n){
    deque<int> cards;

    for(int i = 1; i <= n; i++)
        cards.push_back(i);

    // false일 때 바닥에 버림
    bool flag = true;
    while(cards.size() != 1){
        if(flag){
            cards.pop_front();
        }
        else{
            int card = cards.front();
            cards.pop_front();
            cards.push_back(card);
        }
        flag = !flag;
    }
    cout << cards.front();
}

int main(){
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    solution(n);
    return 0;
}