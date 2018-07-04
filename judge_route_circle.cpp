/**
 * 问题链接：https://leetcode.com/problems/judge-route-circle/description/
 * 编译命令：clang++ judge_route_circle.cpp -std=c++14
 * 回答状态：AC
 */
#include <iostream>

class Solution
{
  public:
    bool judgeCircle(std::string moves)
    {
        int x = 0;
        int y = 0;
        for (auto c : moves) {
            if (c == 'U') {
                y += 1;
            } else if (c == 'D') {
                y -= 1;
            } else if (c == 'L') {
                x -= 1;
            } else if (c == 'R') {
                x += 1;
            }
        }
        if (x == 0 && y == 0) {
            return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.judgeCircle("UD") << std::endl;
    return 0;
}
