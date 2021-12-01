// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        01 Dec 2021
//  @Detail  :        Excel Sheet Column Number (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int titleToNumber(string str) {
        int result = 0;
        for(char &c : str)
            result = result * 26 + (c - 'A' + 1);
        return result;
    }
};
