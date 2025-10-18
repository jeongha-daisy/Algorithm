# Array

## [10808 알파벳 개수](https://www.acmicpc.net/problem/10808)

아스키코드를 이용한다.

    for (int i = 0; i < word.length(); i++){
        int idx = word[i] - 'a';
        alphabets[idx]++;
    }

- sizeof(): 메모리 크기를 바이트 단위로 반환
- size(): 컨테이너 내 요소의 개수 반환
- length(): 문자열의 길이 반환

## [11328 Strfry](https://www.acmicpc.net/problem/11328)

자료구조 vector, pair를 사용하여 테스트케이스 저장

    for (int j = 0; j < test_cases[i].first.length(); j++){
        int idx = test_cases[i].first[j] - 'a';
        alphabets[idx]++;
    }

    for (int j = 0; j < test_cases[i].second.length(); j++){
        int idx = test_cases[i].second[j] - 'a';
        alphabets[idx]--;
    }
