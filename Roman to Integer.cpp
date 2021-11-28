// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        28 Nov 2021
//  @Detail  :        Roman to Integer (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int romanToInt(string str) {
        unordered_map<char, int> cache{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                       {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = cache[str.back()];
        for(int i = str.size() - 2; i >= 0; i--)
        {
            if(cache[str[i]] < cache[str[i + 1]])
                result -= cache[str[i]];
            else
                result += cache[str[i]];
        }
        return result;
    }
};
