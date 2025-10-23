# Linked List

## [1406 에디터](https://www.acmicpc.net/problem/1406)

c++의 list 자료형을 사용한다. 반복자를 이용하여 list에 접근

    cursor = str.erase(--cursor);

    str.insert(cursor, character);

    for(list<char>::iterator t = str.begin(); t != str.end(); t++)
        cout << *t;

## [1158 요세푸스 문제](https://www.acmicpc.net/problem/1158)

요세푸스 순열을 저장하는 변수를 저장하고 반복자를 이용해 접근한다.
반복자가 마지막 요소에 접근했을 때는 첫 번째를 가리키도록 하여 원형 리스트처럼 수행한다.
K번째까지 하나하나 인덱스를 올리는 것이 단점

    if(it == numberList.end())
        it = numberList.begin();
