/**
 * 问题链接：https://leetcode.com/problems/container-with-most-water/description/
 * 编译命令：clang++ container-with-most-water.cpp -std=c++14
 * 回答状态：AC
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_area = 0;
        int l = height.capacity();
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                int dist = j - i;
                int min_height = std::min(height[i], height[j]);
                int area = dist * min_height;
                if (area > max_area) {
                    max_area = area;
                }
            }
        }
        return max_area;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v = {1,8,6,2,5,4,8,3,7};
    std::cout << s.maxArea(v) << std::endl;
    return 0;
}