#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solution(int N, vector<int> buildings){
    // 빌딩의 인덱스 스택
    stack<int> stk;

    // 벤치마킹 가능한 빌딩 수 저장
    int front_buildings[N];

    for(int idx = N - 1; idx >= 0; idx--){
        front_buildings[idx] = 0;
        // cout << "현재 검사 인덱스: " << idx << ", 빌딩 높이: " << buildings[idx] << endl;

        if(idx == N - 1){
            stk.push(idx);
            continue;
        }
    
        while(!stk.empty()){
            int front_height = buildings[stk.top()];
            // cout << "  현재 건물 높이: " <<  buildings[idx] << ", 앞 빌딩 높이: " << front_height << endl;

            if(front_height >= buildings[idx]){    
                // cout << "  앞 건물이 더 높으므로 볼 수 있는 것이 없음"<< endl;
                break;
            }
            else{
                // cout << "  앞 건물이 더 낮으므로 볼 수 있음"<< endl;
                front_buildings[idx] += front_buildings[stk.top()] + 1;
                stk.pop();
            }
        }   
        stk.push(idx);

    }

    long int sum = 0;
    for(int a = 0; a < N;a++)
        sum += front_buildings[a];
    cout << sum;
}

int main(){
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> buildings;
    for(int i =0; i < N; i++){
        int b;
        cin >> b;
        buildings.push_back(b);
    }
    
    solution(N, buildings);
    return 0;
}