// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        12 Dec 2021
//  @Detail  :        Count and Say (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    string cntSay(string str)
    {
        string result = "";
        int n = str.size(), start = 0, end = 0;
        while(end < n)
        {
            while(end < n - 1 && str[end + 1] == str[start])
                end++;
            result += to_string(end - start + 1) + str[start];
            start = end = end + 1;
        }
        return result;
    }
    string countAndSay(int n) {
        string str = "1";
        for(int i = 1; i < n; i++)
            str = cntSay(str);
        return str;
    }
};
