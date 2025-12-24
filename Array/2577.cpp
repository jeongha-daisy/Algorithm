#include <iostream>
using namespace std;

void solution(int a, int b, int c){
    int result;
    result = a * b * c;

    int numbers[10] = {};

    while (result >= 1){
        int n = result % 10;
        numbers[n]++;
        result /= 10;
    }

    for (int i = 0; i < 10; i ++)
        cout << numbers[i] << endl;
    
}

int main(){
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;

    cin >> a >> b >> c;

    solution(a, b, c);
    return 0;
}