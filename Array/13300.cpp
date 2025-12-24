#include <iostream>
using namespace std;

void solution(){

}

int main(){
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    int students[2][7] = {}; //[성별][학년] 저장

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int sex, grade;
        cin >> sex >> grade;
        students[sex][grade]++;
    }


    int rooms = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < 7; j++) {
            rooms += students[i][j] / K;
            if (students[i][j] % K) rooms++;
        }
    }
    cout << rooms;

    return 0;
}