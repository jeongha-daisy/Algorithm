#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

void solution()
{
    vector<int> ans;

    while (true)
    {
        string str;
        cin >> str;

        if (str[0] == '-')
            break;

        stack<char> stk;

        // 안정 검사
        for (int i = 0; i < str.size(); i++)
        {
            char bracket = str[i];
            if (bracket == '{' || stk.empty() || (stk.top() != '{' && bracket == '}'))
            {
                stk.push(bracket);
            }
            else
            {
                stk.pop();
            }
        }

        // 남은 검사
        if (stk.empty())
        {
            ans.push_back(0);
            continue;
        }

        bool isClose = true;
        int count = 0;
        while (!stk.empty())
        {
            char bracket = stk.top();
            stk.pop();

            // 닫힘 차례
            if (isClose && bracket == '{' || !isClose && bracket == '}')
                count++;

            isClose = !isClose;
        }
        ans.push_back(count);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << i + 1 << ". " << ans[i] << endl;
    }
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
    return 0;
}