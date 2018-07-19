/**
 * 问题链接：https://leetcode.com/problems/zigzag-conversion/description/
 * 编译命令：clang++ zigzag_conversion.cpp -std=c++14
 * 回答状态：AC
 */
#include <iostream>
#include <string>
#include <vector>

// 这种思考方式是不行的，只考虑了占位但是没有考虑到顺序
// col: 4
// 0 3 6 9 占据列 n*(col-1)
// (2, 1), (1, 2), (2, 4), (1, 5), (2, 7), (1, 8)

// col: 3
// 0 2 4 6 占据列
// (1, 1), (1, 3)

// 要按顺序来遍历字符串
class Solution
{
  public:
    std::string convert(std::string s, int numRows)
    {

        if (numRows == 1)
            return s;

        // rows存放最终的结果，没有空格
        std::vector<std::string> rows(std::min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s)
        {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;
            curRow += goingDown ? 1 : -1; // 如果是向下走，则要设置下一行的字符
        }

        std::string ret;
        for (std::string row : rows)
            ret += row;
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::string result = s.convert("PAYPALISHIRING", 3);

    std::cout << result << std::endl;
    return 0;
}