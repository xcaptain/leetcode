/**
 * 问题链接：https://leetcode.com/problems/unique-morse-code-words/description/
 * 编译命令：clang++ unique_morse_code_words.cpp -std=c++14
 * 回答状态：AC
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> codes = {};
        int num = 0;
        for (auto word : words)
        {
            string morseCode = toMorseCode(word);
            if (find(codes.begin(), codes.end(), morseCode) == codes.end())
            {
                codes.push_back(morseCode);
                num++;
            }
        }
        return num;
    }

  private:
    string toMorseCode(string &word)
    {
        vector<string> morseCodes = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        string code = "";
        for (auto c : word)
        {
            auto indexInAlphabet = getIndexInAlphabet(c);
            code += morseCodes.at(indexInAlphabet);
        }
        return code;
    }

    int getIndexInAlphabet(char c)
    {
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        if (alphabet.find(c) != string::npos)
        {
            return alphabet.find(c);
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> words = {"mevzi", "mevzi", "gvgs", "qhiwg", "qhijn", "b", "b", "b", "b", "b"};
    Solution s;
    cout << s.uniqueMorseRepresentations(words) << endl;
    return 0;
}
