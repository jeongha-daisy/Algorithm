#include <iostream>
#include <vector>
using namespace std;

void solution(int n, vector<int> seq, int x){
    int ans = 0;
    int numbers[2000001] = {};

    for (int i = 0; i < n; i ++ )
        numbers[seq[i]] = 1;
    
    for (int i = 0; i < n; i ++ ){
        if (x < seq[i])
            continue;
        int target = x - seq[i];
        if(numbers[target] == 1){
            ans++;
        }
    }
    cout << ans / 2;
}

int main(){
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    vector<int> seq;
    cin >> n;

    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        seq.push_back(a);
    }
    cin >> x;
    solution(n, seq, x);
    return 0;
}