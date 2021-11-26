// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        26 Nov 2021
//  @Detail  :        Camelcase Matching (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    bool isMatch(string &str, string &pat)
    {
        int i = 0, n = pat.size();
        for(char &c : str)
            if(i < n && pat[i] == c)
                i++;
            else if(65 <= c && c <= 90)
                return false;
        return i == n;
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool> result(n);
        for(int i = 0; i < n; i++)
            result[i] = isMatch(queries[i], pattern);
        return result;
    }
};
