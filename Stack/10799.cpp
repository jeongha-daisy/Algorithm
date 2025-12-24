#include <iostream>
#include <string>
#include <stack>
using namespace std;

void solution(string str)
{
    stack<char> stk;
    char previous_bracket = ' ';
    int current_sticks = 0;
    int total_sticks = 0;

    for (int i = 0; i < str.size(); i++)
    {
        char bracket = str[i];
        if (bracket == '(')
        {
            stk.push(bracket);
            current_sticks += 1;
        }
        else if (bracket == ')')
        {
            if (previous_bracket == '(')
            {
                current_sticks -= 1;
                total_sticks += current_sticks;
                stk.pop();
            }
            else
            {
                current_sticks -= 1;
                total_sticks += 1;
                stk.pop();
            }
        }
        else
        {
        }
        previous_bracket = bracket;
    }
    cout << total_sticks;
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    solution(str);
    return 0;
}