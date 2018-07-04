/**
 * 问题链接：https://leetcode.com/problems/jewels-and-stones/description/
 * 编译命令：clang++ jewels_and_stones.cpp -std=c++14
 * 回答状态：AC
 */
#include <iostream>
#include <string>
using namespace std;

class Solution
{
  public:
    int numJewelsInStones(string J, string S)
    {
        int num = 0;
        for (auto it : S)
        {
            if (J.find(it) != string::npos)
            {
                num++;
            }
        }
        return num;
    }
};

int main()
{
    Solution s;
    cout << s.numJewelsInStones("hello", "world") << endl;

    return 0;
}
