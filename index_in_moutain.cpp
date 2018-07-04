/**
 * 问题链接：https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
 * 编译命令：clang++ index_in_moutain.cpp -std=c++14
 * 回答状态：AC
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int peakIndexInMountainArray(vector<int> &A)
    {
        int len = A.size();
        for (int i = 0; i < len; i++)
        {
            if (isMoutain(i, A))
            {
                return i;
            }
        }
        return 0;
    }

  private:
    bool isMoutain(int index, vector<int> &A)
    {
        int len = A.size();
        for (int i = 0; i < index - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                return false;
            }
        }
        for (int i = index; i < len - 1; i++)
        {
            if (A[i] < A[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> A = {0,2,1,0};
    cout << "index: " << s.peakIndexInMountainArray(A) << endl;
    return 0;
}
