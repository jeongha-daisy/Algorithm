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

    vector <pair<string, string> > test_cases;
    test_cases.push_back(make_pair(s1, s2));

## [1475 방 번호](https://www.acmicpc.net/problem/1475)

6번, 9번 숫자는 같이 사용 가능하므로 (6번 사용량 + 9번 사용량) / 2의 올림 수가 두 숫자를 사용하는 최종 세트의 양이 된다.
ex. 99996 => 9번 4개, 6번 1개 => 9번, 6번 한 세트 + 9번, 뒤집은 9번 한 세트 + 9번 한 세트 => 총 3 세트

    ans = max(ans, (numberSet[6] + numberSet[9] + 1)/2);
