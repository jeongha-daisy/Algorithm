# Array

## [10808 알파벳 개수](https://www.acmicpc.net/problem/10808)

아스키코드를 이용한다.

    for (int i = 0; i < word.length(); i++){
        int idx = word[i] - 'a';
        alphabets[idx]++;
    }
