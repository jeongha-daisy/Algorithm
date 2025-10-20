#include <iostream>
#include <algorithm>
using namespace std;

void solution(int roomNumber){

    // 플라스틱 숫자 세트
    int numberSet[10] = {};
    int ans = 0;
    while(roomNumber >= 1){
        int N = roomNumber % 10;
        numberSet[N]++;
        roomNumber /= 10;
    }

    for (int i = 0; i < 10; i++){
        if (i != 6 && i != 9) {
            ans = max(ans, numberSet[i]);
        }
    }
    ans = max(ans, (numberSet[6] + numberSet[9] + 1)/2);
    cout << ans;
}

int main(){
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    int roomNumber;
    cin >> roomNumber;
    
    solution(roomNumber);
    return 0;
}