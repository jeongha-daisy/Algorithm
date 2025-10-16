#include <iostream>
#include <string>
using namespace std;

void solution(string word){
    int alphabets[26] = {};
    
    for (int i = 0; i < word.length(); i++){
        int idx = word[i] - 'a';
        alphabets[idx]++;
    }

    for (int i = 0; i < 26; i++)
        cout << alphabets[i] << " ";
}

int main(){
    string word;
    cin >> word;
    solution(word);
    return 0;
}