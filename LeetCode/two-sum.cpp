#include <iostream>
#include <vector>
using namespace std;

// 첫 번째 솔루션 35ms O(N^2)
vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    vector<int> nums;
    int target;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        nums.push_back(k);
    }
    cin >> target;

    twoSum(nums, target);
    return 0;
}