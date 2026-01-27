#include <iostream>
#include <string>

using namespace std;

string s;
int answer;

void solution()
{
    int pre_index = 0;

    // 한 번이라도 마이너스가 나오면 그 뒤를 모두 뺄셈을 수행한다.
    bool hasMinus = false;

    for (int i = 0; i < s.size(); i++)
    {
        // 연산자 기준 앞의 숫자들을 연산한다.
        if (s[i] != '-' && s[i] != '+')
            continue;

        // 앞서 마이너스가 있는 것을 확인했다면 모두 뺄셈 수행
        if (hasMinus)
            answer -= atoi(&s[pre_index]);

        // 기본적으로 모두 덧셈 수행
        else
            answer += atoi(&s[pre_index]);

        // 현재 연산자가 마이너스인지 확인
        if (s[i] == '-')
        {
            hasMinus = true;
        }

        // 연산자 다음 숫자 확인용 인덱스
        pre_index = i + 1;
    }

    // 마지막 숫자
    if (hasMinus)
        answer -= atoi(&s[pre_index]);
    else
        answer += atoi(&s[pre_index]);

    cout << answer;
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;

    solution();
    return 0;
}