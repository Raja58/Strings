// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        01 Dec 2021
//  @Detail  :        Excel Sheet Column Title (LeetCode)
//  ============================
//  -->

class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        while(n)
        {
            char c = 'A' + (n - 1) % 26;
            result = c + result;
            n = (n - 1) / 26;
        }
        return result;
    }
};
