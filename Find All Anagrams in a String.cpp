// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        18 Nov 2021
//  @Detail  :         Find All Anagrams in a String (LeetCode)
//  ============================
//  -->

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> orig(26), dup(26), result;
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
