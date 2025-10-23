#include <iostream>
#include <list>
#include <vector>

using namespace std;

void solution(int N, int K){

    list<int> numberList;
    vector<int> results;

    for(int i = 1 ; i <= N; i++){
        numberList.push_back(i);
    } 

    list<int>::iterator it = numberList.begin();
    int index = 0;

    while(true){
        if(numberList.empty())
            break;

        if(it == numberList.end())
            it = numberList.begin();

        index ++;
        if(index == K){
            results.push_back(*it);
            it = numberList.erase(it);
            it--;
            index = 0;
        }
        it++;
    }

    // 출력
    cout << "<";
    for (int i = 0; i < N - 1; i++)
        cout << results[i] << ", ";
    cout << results[N - 1] << ">";
}

int main(){
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    solution(N, K);
    return 0;
}