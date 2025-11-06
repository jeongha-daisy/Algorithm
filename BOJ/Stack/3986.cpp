#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int solution(vector<string> str_array)
{
    int ans = 0;
    for (string str : str_array)
    {
        int str_size = str.size();
        stack<char> stk;

        // 홀수면 안좋은 단어
        if (str_size % 2 == 1)
        {
            continue;
        }
        for (int i = 0; i < str_size; i++)
        {
            if (stk.empty() || stk.top() != str[i])
            {
                stk.push(str[i]);
                continue;
            }
            stk.pop();
        }

        if (stk.empty())
            ans += 1;
    }

    return ans;
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<string> str_array;
    for (int i = 0; i < N; i++)
    {
        string a;
        cin >> a;
        str_array.push_back(a);
    }
    cout << solution(str_array);
    return 0;
}