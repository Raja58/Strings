// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        28 Nov 2021
//  @Detail  :        Integer to Roman (LeetCode)
//  ============================
//  -->

class Solution {
public:
    string intToRoman(int num) {
        vector<int> integer{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result = "";
        for(int i = 0; i < integer.size() && num > 0; i++)
        {
            while(num >= integer[i])
            {
                num -= integer[i];
                result += roman[i];
            }
        }
        return result;
    }
};
