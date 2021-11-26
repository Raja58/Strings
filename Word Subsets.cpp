// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        26 Nov 2021
//  @Detail  :        Word Subsets (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    vector<int> count(string &str)
    {
        vector<int> result(26);
        for(char &c : str)
            result[c - 'a']++;
        return result;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26);
        
        for(string &x : words2)
        {
            vector<int> temp = count(x);
            for(int i = 0; i < 26; i++)
                freq[i] = max(freq[i], temp[i]);
        }
        
        vector<string> result;
        
        for(string &x : words1)
        {
            vector<int> temp = count(x);
            bool valid = true;
            for(int i = 0; i < 26; i++)
                if(freq[i] != 0 && temp[i] < freq[i])
                {
                    valid = false;
                    break;
                }
            if(valid)
                result.push_back(x);
        }
        return result;
    }
};
