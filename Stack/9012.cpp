#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

void solution(vector<string> str_array)
{
    vector<string> ans;

    for (string str : str_array)
    {

        stack<char> stk;
        for (int i = 0; i < str.size(); i++)
        {
            char bracket = str[i];
            if (bracket == '(')
            {
                stk.push(bracket);
            }
            else
            {
                if (stk.empty() || stk.top() == ')')
                {
                    stk.push(')');
                    break;
                }
                stk.pop();
            }
        }
        if (!stk.empty())
            ans.push_back("NO");
        else
            ans.push_back("YES");
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    vector<string> str_array;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        str_array.push_back(s);
    }
    solution(str_array);
    return 0;
}