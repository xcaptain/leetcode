/**
 * 问题链接：https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 * 编译命令：clang++ two_sum.cpp -std=c++14
 * 回答状态：AC
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int len = numbers.size();
        int i = 0;
        while (i < len)
        {
            int suplement = target - numbers[i];
            vector<int>::iterator start = numbers.begin();
            std::advance(start, i+1);
            vector<int>::iterator it = find(start, numbers.end(), suplement);
            if (it != numbers.end())
            {
                int pos = it - numbers.begin();
                return {i + 1, pos + 1};
            }
            // 因为是已经排序好了的，所以一个不满足，相同的几个都可以跳过
            int count = std::count(start, numbers.end(), numbers[i]);
            i = i + count + 1;
        }
        return {0, 0};
    }
};

int main(int argc, char const *argv[])
{
    vector<int> numbers = {0, 0, 3, 4};
    int target = 0;
    Solution s;
    vector<int> result = s.twoSum(numbers, target);

    cout << "index: " << result[0] << ", " << result[1] << endl;
    return 0;
}
