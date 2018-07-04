/**
 * 问题链接：https://leetcode.com/problems/reverse-bits/description/
 * 编译命令：clang++ reverse_bits.cpp -std=c++14
 * 回答状态：AC
 */
#include <iostream>
#include <bitset>
#include <cmath>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        std::bitset<32> bits(n);
        std::string s_n = bits.to_string();
        int p = 31; // 最高位是31次
        int co = 0;
        int num = 0;
        // 反向迭代字符串用rbegin, rend
        for (auto i = s_n.rbegin(); i != s_n.rend(); i++) {
            std::cout << *i;
            if (*i == '0') {
                co = 0;
            } else {
                co = 1;
            }
            num += co * std::pow(2, p);
            p--;
        }
        return num;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.reverseBits(43261596) << std::endl;
    return 0;
}
