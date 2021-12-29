// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        29 Dec 2021
//  @Detail  :        Longest Substring Without Repeating Characters (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        if(str.empty())
            return 0;
        unordered_map<char, int> cache;
        int n = str.size(), startIdx = 0;
        vector<int> result{0, 0};
        for(int i = 0; i < n; i++)
        {
            if(cache.find(str[i]) != cache.end())
            {
                if(startIdx <= cache[str[i]])
                    startIdx = cache[str[i]] + 1;
            }
            
            if(result[1] - result[0] < i - startIdx)
                    result = {startIdx, i};
            cache[str[i]] = i;
        }
        return result[1] - result[0] + 1;
    }
};
