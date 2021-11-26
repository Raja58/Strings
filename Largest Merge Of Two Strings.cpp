// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        26 Nov 2021
//  @Detail  :        Largest Merge Of Two Strings (LeetCode)
//  ============================
//  -->

class Solution {
public:
    string largestMerge(string word1, string word2) {
        if(word1.empty() || word2.empty())
            return word1 + word2;
        
        if(word1 > word2)
            return word1[0] + largestMerge(word1.substr(1), word2);
        return word2[0] + largestMerge(word1, word2.substr(1));
    }
};
