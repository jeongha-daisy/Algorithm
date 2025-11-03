#include <iostream>
#include <string>
#include <stack>
using namespace std;

void solution()
{
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        string str;
        getline(cin, str);
        if (str == ".")
        {
            break;
        }

        stack<char> stk;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(' || str[i] == '[')
            {
                stk.push(str[i]);
            }
            else if (str[i] == ')')
            {
                if (!stk.empty() && stk.top() == '(')
                {
                    stk.pop();
                }
                else
                {
                    cout << "no\n";
                    break;
                }
            }
            else if (str[i] == ']')
            {

                if (!stk.empty() && stk.top() == '[')
                {
                    stk.pop();
                }
                else
                {
                    cout << "no\n";
                    break;
                }
            }
            else if (str[i] == '.')
            {
                if (!stk.empty())
                    cout << "no\n";
                else
                    cout << "yes\n";
            }
            else
            {
                continue;
            }
        }
    }
    solution();
    return 0;
}