// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        18 Nov 2021
//  @Detail  :        Minimum Window Substring (LeetCode)
//  ============================
//  -->

class Solution {
public:
    string minWindow(string s, string p) {
        unordered_map<char, int> orig, dup;
        vector<int> result = {-1, -1};
        for(char &c : p)
            orig[c]++;
        int totalChar = orig.size();
        int charsDone = 0, start = 0, len = INT_MAX;
        for(int i = 0; i < s.size(); i++)
        {
            dup[s[i]]++;
            if(dup[s[i]] == orig[s[i]])
                charsDone++;
            while(start <= i && charsDone == totalChar)
            {
                if(i - start + 1 < len)
                    len = i - start + 1, result = {start, i};
                if(dup[s[start]] == orig[s[start]])
                    charsDone--;
                dup[s[start]]--;
                start++;
            }
        }
        return result[0] != - 1 ? s.substr(result[0], result[1] - result[0] + 1) : "";
    }
};
