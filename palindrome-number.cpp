/**
 * 问题链接：https://leetcode.com/problems/palindrome-number/description/
 * 编译命令：clang++ palindrome-number.cpp -std=c++14
 * 回答状态：AC
 */

#include <iostream>

class Solution
{
  public:
    bool isPalindrome(int x)
    {
        std::string s = std::to_string(x);
        int i = 0;
        while (i < s.length() / 2) {
            int j = s.length() - i - 1;
            if (s[i] != s[j]) {
                return false;
            }
            i++;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.isPalindrome(121) << std::endl;
    std::cout << s.isPalindrome(1212) << std::endl;
    return 0;
}
