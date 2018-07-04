/**
 * 问题链接：https://leetcode.com/problems/flipping-an-image/description/
 * 编译命令：clang++ flip_image.cpp -std=c++14
 * 回答状态：AC
 */
#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
  public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>> &A)
    {
        std::vector<std::vector<int>> result;
        for (std::vector<int> row : A)
        {
            std::vector<int> flipedRow = flipRow(row);
            std::vector<int> invertedRow = invertRow(flipedRow);
            result.push_back(invertedRow);
        }
        return result;
    }

  private:
    std::vector<int> flipRow(std::vector<int> &row)
    {
        std::vector<int> result;
        int len = row.size();
        for (int i = len-1; i >= 0; i--)
        {
            result.push_back(row[i]);
        }
        return result;
    }
    std::vector<int> invertRow(std::vector<int> &row)
    {
        std::vector<int> result;
        for (auto elem : row)
        {
            int value = elem ^ 1;
            result.push_back(value);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> A = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 0, 0},
    };
    Solution s;
    std::vector<std::vector<int>> result = s.flipAndInvertImage(A);
    for (auto row : result)
    {
        for (auto value : row)
        {
            std::cout << value << ",";
        }
        std::cout << "\n";
    }
    return 0;
}
