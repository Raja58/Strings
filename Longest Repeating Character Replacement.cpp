// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        25 Nov 2021
//  @Detail  :        Longest Repeating Character Replacement (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int characterReplacement(string str, int k) {
        vector<int> freq(26, 0);
        int start = 0, end = 0, result = 0, maxFreq = 0;
        for(end = 0; end < str.size(); end++)
        {
            freq[str[end] - 'A']++;
            if(maxFreq < freq[str[end] - 'A'])
                maxFreq = freq[str[end] - 'A'];
            
            if((end - start + 1) - maxFreq > k)    //last element is surely a different element
            {
                result = max(result, end - start);
                freq[str[start] - 'A']--;
                start++;
                maxFreq = *max_element(freq.begin(), freq.end());
            }
        }
        result = max(result, end - start);
        return result;
    }
};
