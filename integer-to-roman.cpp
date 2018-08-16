/**
 * 问题链接：https://leetcode.com/problems/integer-to-roman/description/
 * 编译命令：clang++ integer-to-roman.cpp -std=c++14
 * 回答状态：AC
 */

#include <iostream>
#include <map>

// 1 ~ 3999
/**
Symbol       Value
I             1
II            2
III           3
IV            4
V             5
VI            6
VII           7
VIII          8
IX            9
X             10
L             50
C             100
D             500
M             1000
*/
// 1994 M(CM)(XC)IV 1000 + 900 + 90 + 4
class Solution
{
  public:
    std::string intToRoman(int num)
    {
        // 生成符号表
        // 解析数字，从对应的符号表中取出符号
        if (num >= 1 && num <= 9)
        {
            return this->intToRoman_1(num);
        }
        else if (num >= 10 && num <= 99)
        {
            // 2位数
            return this->intToRoman_2(num);
        }
        else if (num >= 100 && num <= 999)
        {
            // 3 digits
            return this->intToRoman_3(num);
        }
        else if (num >= 1000 && num <= 9999)
        {
            // 4 digits
            return this->intToRoman_4(num);
        }
        else
        {
            return "";
        }
    }

  private:
    std::string intToRoman_1(int num)
    {
        std::map<int, std::string> charDict;
        charDict[1] = "I";
        charDict[2] = "II";
        charDict[3] = "III";
        charDict[4] = "IV";
        charDict[5] = "V";
        charDict[6] = "VI";
        charDict[7] = "VII";
        charDict[8] = "VIII";
        charDict[9] = "IX";
        return charDict[num];
    }

    std::string intToRoman_2(int num)
    {
        int rem = num % 10;
        int round_part = num - rem;
        std::map<int, std::string> charDict;
        charDict[10] = "X";
        charDict[20] = "XX";
        charDict[30] = "XXX";
        charDict[40] = "XL";
        charDict[50] = "L";
        charDict[60] = "LX";
        charDict[70] = "LXX";
        charDict[80] = "LXXX";
        charDict[90] = "XC";
        return charDict[round_part] + this->intToRoman_1(rem);
    }

    std::string intToRoman_3(int num)
    {
        int rem = num % 100;
        int round_part = num - rem;
        std::map<int, std::string> charDict;
        charDict[100] = "C";
        charDict[200] = "CC";
        charDict[300] = "CCC";
        charDict[400] = "CD";
        charDict[500] = "D";
        charDict[600] = "DC";
        charDict[700] = "DCC";
        charDict[800] = "DCCC";
        charDict[900] = "CM";
        return charDict[round_part] + this->intToRoman_2(rem);
    }

    std::string intToRoman_4(int num)
    {
        int rem = num % 1000;
        int round_part = num - rem;
        std::map<int, std::string> charDict;
        charDict[1000] = "M";
        charDict[2000] = "MM";
        charDict[3000] = "MMM";
        return charDict[round_part] + this->intToRoman_3(rem);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.intToRoman(9) << std::endl;
    std::cout << s.intToRoman(58) << std::endl;
    std::cout << s.intToRoman(1994) << std::endl;
    return 0;
}