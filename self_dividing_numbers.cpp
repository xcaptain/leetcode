/**
 * 问题链接：https://leetcode.com/problems/self-dividing-numbers/description/
 * 编译命令：clang++ self_dividing_numbers.cpp -std=c++14
 * 回答状态：AC
 */
#include <iostream>
#include <vector>

class Solution
{
  public:
    std::vector<int> selfDividingNumbers(int left, int right)
    {
        std::vector<int> result;
        for (int i = left; i <= right; i++)
        {
            if (this->selfDividable(i))
            {
                result.push_back(i);
            }
        }
        return result;
    }

  private:
    bool selfDividable(int n)
    {
        std::string s = std::to_string(n);
        for (char c : s)
        {
            // std::string s;
            // s.push_back(c);
            int i = std::stoi(std::string(1, c));
            if (i == 0 || n % i != 0)
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
    std::vector<int> r = s.selfDividingNumbers(1, 20);

    for (auto i : r)
    {
        std::cout << i << std::endl;
    }
    std::cout << "\n";
    return 0;
}
