// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        18 Nov 2021
//  @Detail  :        Substring with Concatenation of All Words (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    bool updateResult(int start, int end, int wordLen, string &s, unordered_map<string, int> cache)
    {
        for(int i = start; i <= end; i += wordLen)
            if(cache[s.substr(i, wordLen)])
                cache[s.substr(i, wordLen)]--;
            else
                return false;
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        string p = "";
        for(string &x : words)
            p = p + x;
        unordered_map<string, int> cache;
        for(string &x : words)
            cache[x]++;
        vector<int> orig(26), dup(26), result;
        int wordLen = words[0].size();
        for(char &c : p)
            orig[c - 'a']++;
        int totalChar = 0;
        for(int i : orig)
            if(i)
                totalChar++;
        int charsDone = 0, start = 0;
        for(int i = 0; i < s.size(); i++)
        {
            dup[s[i] - 'a']++;
            if(dup[s[i] - 'a'] == orig[s[i] - 'a'])
                charsDone++;
            while(start <= i && charsDone == totalChar)
            {
                if(i - start + 1 == p.size())
                    if(updateResult(start, i, wordLen, s, cache))
                        result.push_back(start);
                if(dup[s[start]- 'a'] == orig[s[start] - 'a'])
                    charsDone--;
                dup[s[start]- 'a']--;
                start++;
            }
        }
        return result;
    }
};
