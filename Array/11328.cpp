#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void solution(int N, vector<pair<string, string> > test_cases){
    for (int i = 0; i < test_cases.size(); ++i){
        int alphabets[26] = {};

        for (int j = 0; j < test_cases[i].first.length(); j++){
            int idx = test_cases[i].first[j] - 'a';
            alphabets[idx]++;
        }

        for (int j = 0; j < test_cases[i].second.length(); j++){
            int idx = test_cases[i].second[j] - 'a';
            alphabets[idx]--;
        }
        
        int isPossible = 1;
        for (int j = 0; j < 26; j++){
            if (alphabets[j] == 0)
                continue;
            else{
                isPossible = 0;
                break;
            }
        }
        if(isPossible)
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;

    }

}

int main(){
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    vector <pair<string, string> > test_cases;
    cin >> N;
    for (int i = 0; i < N; i++){
        string s1, s2;
        cin >> s1 >> s2;

        test_cases.push_back(make_pair(s1, s2));
    }

    solution(N, test_cases);
    return 0;
}