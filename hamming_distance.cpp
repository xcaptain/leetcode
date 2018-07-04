/**
 * 问题链接：https://leetcode.com/problems/hamming-distance/description/
 * 编译命令：clang++ hamming_distance.cpp -std=c++14
 * 回答状态：AC
 */
#include <iostream>
#include <bitset>

class Solution {
public:
    int hammingDistance(int x, int y) {
        std::string s_x = std::bitset<64>(x).to_string();
        std::string s_y = std::bitset<64>(y).to_string();
        int num = 0;
        for (int i = 0; i< 64; i++) {
            if (s_x[i] != s_y[i]) {
                num++;
            }
        }
        return num;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.hammingDistance(1, 4) << std::endl;
    return 0;
}
