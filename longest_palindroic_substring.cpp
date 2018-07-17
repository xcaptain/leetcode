/**
 * 问题链接：https://leetcode.com/problems/longest-palindromic-substring/description/
 * 编译命令：clang++ longest_palindroic_substring.cpp -std=c++14
 * 回答状态：Time Limit Exceeded
 */
#include <iostream>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

// TODO: fixme
class Solution
{
  public:
    std::string longestPalindrome(std::string s)
    {
        int l = s.length();
        std::string result = s.substr(0, 1);
        int max_len = 1;
        for (int i = 0; i < l - 1; i++)
        {
            for (int j = i + 1; j < l; j++)
            {
                std::string sub_s = s.substr(i, j - i + 1);
                // std::cout << "substring: " << sub_s << std::endl;
                if (this->isPalindrome(sub_s))
                {
                    int sub_l = j - i + 1;
                    if (sub_l > max_len)
                    {
                        max_len = sub_l;
                        result = sub_s;
                    }
                }
            }
        }
        return result;
    }

  private:
    bool isPalindrome(std::string s)
    {
        int start = 0;
        int end = s.length() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        // std::cout << "palindroe: " << s << std::endl;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::string s1 = "banana";
    std::string s2 = "a";
    // assert(s.longestPalindrome(s1) == ps1);
    std::cout << s.longestPalindrome(s1) << std::endl;
    std::cout << s.longestPalindrome(s2) << std::endl;
    return 0;
}
