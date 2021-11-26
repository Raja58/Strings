// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        26 Nov 2021
//  @Detail  :        Minimum Number of Steps to Make Two Strings Anagram (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    vector<int> count(string &x)
    {
        vector<int> freq(26);
        for(char &c : x)
            freq[c - 'a']++;
        return freq;
    }
    
    int minSteps(string s, string t) {
        vector<int> freq = count(s), temp = count(t);
        
        int result = 0;
        for(int i = 0; i < 26; i++)
            if(temp[i] > freq[i])
                result += temp[i] - freq[i];
        return result;
    }
};
