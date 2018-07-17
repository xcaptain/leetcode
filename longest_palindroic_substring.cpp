/**
 * 问题链接：https://leetcode.com/problems/longest-palindromic-substring/description/
 * 编译命令：clang++ longest_palindroic_substring.cpp -std=c++14
 * 回答状态：AC
 */
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    std::string longestPalindrome(std::string s)
    {
        int l = s.length();
        int boundTable[l][l]; // s[i..j]如果是回文串，则值是串的长度
        std::string sub_s;

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < l; j++)
            {
                boundTable[i][j] = 0;
            }
        }

        // 长度为1的子串都是回文串
        int maxLen = 1;
        for (int i = 0; i < l; i++)
        {
            boundTable[i][i] = 1;
            sub_s = s.substr(i, 1);
            // std::cout << "sub_s: " << sub_s << std::endl;
        }

        // 查找长度为2的回文串
        int start = 0;
        for (int i = 0; i < l - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                boundTable[i][i + 1] = 2;
                maxLen = 2;
                start = i;
                sub_s = s.substr(i, 2);
                // std::cout << "sub_s: " << sub_s << std::endl;
            }
        }

        // 查找长度为3以上的回文串
        for (int k = 3; k <= l; k++)
        {
            for (int i = 0; i < l - k + 1; i++)
            {
                int j = i + k - 1;
                // 如果i+1到j-1已经是回文串，而s[i] == s[j]，则i..j也是回文串
                if (boundTable[i+1][j-1] != 0 && s[i] == s[j])
                {
                    boundTable[i][j] = k;
                    if (k > maxLen)
                    {
                        maxLen = k;
                        sub_s = s.substr(i, k);
                    }
                }
            }
        }

        return sub_s;
    }

  private:
    bool isPalindrome(std::string s)
    {
        int start = 0;
        int end = s.length() - 1;
        while (start < end)
        {
            if (s[start] != s[end])
            {
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
    std::string s1 = "bananaa";
    std::string s2 = "a";
    // assert(s.longestPalindrome(s1) == ps1);
    std::cout << s.longestPalindrome(s1) << std::endl;
    std::cout << s.longestPalindrome(s2) << std::endl;
    return 0;
}
