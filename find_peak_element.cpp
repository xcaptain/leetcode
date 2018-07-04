/**
 * 问题链接：https://leetcode.com/problems/find-peak-element/description/
 * 编译命令：clang++ find_peak_element.cpp -std=c++14
 * 回答状态：AC
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int findPeakElement(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
        {
            return 0;
        }
        else if (len == 2)
        {
            if (nums[0] < nums[1])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            for (int i = 0; i < len; i++)
            {
                if (i == 0)
                {
                    if (nums[i] > nums[i + 1])
                    {
                        return i;
                    }
                }
                else if (i == len - 1)
                {
                    if (nums[i] > nums[i - 1])
                    {
                        return i;
                    }
                }
                else
                {
                    if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                    {
                        return i;
                    }
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    Solution s;
    cout << "peak: " << s.findPeakElement(nums) << endl;
    return 0;
}
