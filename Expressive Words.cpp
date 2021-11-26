// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        26 Nov 2021
//  @Detail  :        Expressive Words (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    bool isExpressive(string &str, string &x)
    {
        int i = 0, j = 0, n = str.size(), m = x.size();
        while(i < n && j < m)
        {
            if(str[i] != x[j])
                return false;
            
            int idx1 = i, idx2 = j;
            while(idx1 < n && str[idx1] == str[i])
                idx1++;
            while(idx2 < m && x[idx2] == x[j])
                idx2++;
            
            if(idx1 - i != idx2 - j && idx1 - i < max(3, idx2 - j))
                return false;
            
            i = idx1;   j = idx2;
        }
        return i == n && j == m;
    }
    
    int expressiveWords(string str, vector<string>& words) {
        int result = 0;
        for(string &x : words)
            result += isExpressive(str, x);
        return result;
    }
};
