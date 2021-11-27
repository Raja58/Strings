// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        27 Nov 2021
//  @Detail  :        Word Pattern (LeetCode)
//  ============================
//  -->

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> cache;
        unordered_set<string> table;
        
        int i = 0;
        stringstream ss(str);
        string word;
        while(getline(ss, word, ' '))
        {
            if(i == pattern.size())
                return false;
            
            if(cache.find(pattern[i]) != cache.end())
            {
                if(cache[pattern[i]] != word)
                    return false;
            }
            else
            {
                if(table.find(word) != table.end())
                    return false;
                cache[pattern[i]] = word;
            }
            
            table.insert(word);
            i++;
        }
        return i == pattern.size();
    }
};
