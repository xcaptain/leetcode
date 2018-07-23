/**
 * 问题链接：https://leetcode.com/problems/reverse-integer/description/
 * 编译命令：clang++ reverse_integer.cpp -std=c++14
 * 回答状态：AC
 */
#include <iostream>
#include <string>

class Solution
{
  public:
    int reverse(int x)
    {
        std::string s = std::to_string(x);
        int result = 0;
        bool is_positive = true;
        std::string rs;
        for (auto i = s.rbegin(); i != s.rend(); i++)
        {
            if (*i == '-')
            {
                is_positive = !is_positive;
            }
            else
            {
                rs.push_back(*i);
            }
        }
        std::string trs;
        if (rs.length() == 1)
        {
            trs = rs;
        }
        else
        {
            for (int i = 0; i < rs.length(); i++)
            {
                if (rs[i] == '0' && rs[i + 1] == 0)
                {
                    continue;
                }
                else
                {
                    trs.push_back(rs[i]);
                }
            }
        }
        try
        {
            if (!is_positive)
            {
                return 0 - std::stoi(trs);
            }
            return std::stoi(trs);
        }
        catch (std::out_of_range e)
        {
            return 0;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << "reversed= " << s.reverse(-0) << std::endl;
    std::cout << "reversed= " << s.reverse(-123) << std::endl;
    std::cout << "reversed= " << s.reverse(-3210) << std::endl;
    std::cout << "reversed= " << s.reverse(3012) << std::endl;
    std::cout << "reversed= " << s.reverse(1534236469) << std::endl;

    return 0;
}
