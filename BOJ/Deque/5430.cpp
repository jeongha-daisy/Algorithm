#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
using namespace std;

struct TestCase
{
    string functions;
    int array_size;
    deque<int> numbers;
};

deque<int> strToVector(string str)
{
    deque<int> numbers;
    string clean_str = str.substr(1, str.length() - 2);
    stringstream ss(clean_str);
    string token;
    while (getline(ss, token, ','))
    {
        if (!token.empty())
        {
            numbers.push_back(stoi(token));
        }
    }
    return numbers;
}
string dequeToString(bool forward, deque<int> deq)
{
    string result;
    if (deq.empty())
        return "[]";
    result += '[';

    while (!deq.empty())
    {
        if (forward)
        {
            result += to_string(deq.front());
            result += ',';
            deq.pop_front();
        }
        else
        {
            result += to_string(deq.back());
            result += ',';
            deq.pop_back();
        }
    }

    // 마지막 , 삭제
    result = result.substr(0, result.size() - 1);
    result += ']';
    return result;
}

void solution(int T, vector<TestCase> testCases)
{
    for (int i = 0; i < T; i++)
    {
        bool forward = true;
        bool isPossible = true;
        TestCase ts = testCases[i];

        for (int j = 0; j < ts.functions.size(); j++)
        {

            if (ts.functions[j] == 'R')
                // 뒤집기
                forward = !forward;
            else
            {
                // 버리기
                if (forward)
                {
                    if (ts.numbers.empty())
                    {
                        isPossible = false;
                        break;
                    }
                    ts.numbers.pop_front();
                }

                else
                {

                    if (ts.numbers.empty())
                    {
                        isPossible = false;
                        break;
                    }
                    ts.numbers.pop_back();
                }
            }
        }
        if (isPossible)
            cout << dequeToString(forward, ts.numbers) << endl;
        else
            cout << "error\n";
    }
}
int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    vector<TestCase> testCases;

    for (int i = 0; i < T; i++)
    {
        string functions;
        cin >> functions;

        int array_size;
        cin >> array_size;

        string numbers_str;
        deque<int> numbers;
        cin >> numbers_str;
        numbers = strToVector(numbers_str);

        TestCase ts;
        ts.functions = functions;
        ts.array_size = array_size;
        ts.numbers = numbers;

        testCases.push_back(ts);
    }

    solution(T, testCases);
    return 0;
}
