#include <iostream>
#include <string>
using namespace std;

void solution(string a, string b){
    int alphabets[26] = {};
    int ans = 0;
    for (int i = 0; i < a.length(); i++){
        alphabets[a[i] - 'a']++;
    }

    for (int i = 0; i < b.length(); i++){
        alphabets[b[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++){
        if (alphabets[i] != 0)
            ans += abs(alphabets[i]);
    }
    cout << ans;
}

int main(){
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string a, b;
    cin >> a >> b;

    solution(a, b);
    return 0;
}