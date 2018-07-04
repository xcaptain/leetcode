/**
 * 问题链接：https://leetcode.com/problems/number-of-1-bits/description/
 * 编译命令：clang++ number_of_1_bits.cpp -std=c++14
 * 回答状态：AC
 */
#include <iostream>
#include <bitset>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        std::string s_n = std::bitset<32>(n).to_string();
        int num = 0;

        for (auto c : s_n) {
            if (c == '1') {
                num++;
            }
        }
        return num;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.hammingWeight(11) << std::endl;
    return 0;
}
