#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string str)
{
    int ans = 0;
    // 괄호의 모양과 자식 괄호의 점수를 저장한다.
    stack<pair<char, int>> stk;

    for (int i = 0; i < str.size(); i++)
    {
        char bracket = str[i];
        if (bracket == '(')
        {
            stk.push(make_pair('(', 0));
        }
        else if (bracket == '[')
        {
            stk.push(make_pair('[', 0));
        }
        else if (bracket == ')')
        {
            // 스택이 비었거나 괄호 짝이 맞지 않는 경우 올바르지 못한 괄호열이므로 0을 출력
            if (stk.empty() || stk.top().first == '[')
                return 0;

            // 짝꿍이 되는 열린 괄호를 현재 괄호로 본다.
            pair<char, int> my_bracket = stk.top();
            stk.pop();

            // pop 수행 후 스택이 비었다면 바깥을 감싸는 바깥 괄호가 더이상 없는 것이다.
            if (stk.empty())
            {
                // 내부 괄호의 숫자 * 2를 저장한다. 값이 0이라면 내부 괄호가 없는 것이므로 2를 저장한다.
                if (my_bracket.second == 0)
                    ans += 2;
                ans += my_bracket.second * 2;
                continue;
            }

            // pop 수행 후 스택이 비어있지 않다면 바깥을 감싸는 바깥 괄호가 있다.
            pair<char, int> exterior_bracket = stk.top();
            stk.pop();

            // 현재 내 괄호의 점수 값이 0이면 내부 괄호가 없는 것이다.
            if (my_bracket.second == 0)
            {
                // 바깥 괄호에 2점만 추가한다.
                exterior_bracket.second += 2;
            }
            else
            {
                // 내 괄호의 점수 값이 0이 아니면 내부 괄호가 있는 것이므로 내 점수 값에 2를 곱해 바깥 괄호의 점수 값에 저장한다.
                exterior_bracket.second += my_bracket.second * 2;
            }

            // 갱신된 바깥 괄호를 다시 스택에 추가한다.
            stk.push(exterior_bracket);
        }
        else if (bracket == ']')
        {
            // 스택이 비었거나 괄호 짝이 맞지 않는 경우 올바르지 못한 괄호열이므로 0을 출력
            if (stk.empty() || stk.top().first == '(')
                return 0;

            pair<char, int> my_bracket = stk.top();
            stk.pop();
            if (stk.empty())
            {
                if (my_bracket.second == 0)
                    ans += 3;
                ans += my_bracket.second * 3;
                continue;
            }
            pair<char, int> exterior_bracket = stk.top();
            stk.pop();
            if (my_bracket.second == 0)
            {
                exterior_bracket.second += 3;
            }
            else
            {
                exterior_bracket.second += my_bracket.second * 3;
            }

            stk.push(exterior_bracket);
        }
        else
        {
        }
    }

    if (!stk.empty())
        return 0;

    return ans;
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;

    cout << solution(str);
    return 0;
}