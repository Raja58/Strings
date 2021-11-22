// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        22 Nov 2021
//  @Detail  :        Longest Word in Dictionary through Deleting (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    static bool myComp(string &x, string &y)
    {
        if(x.size() == y.size())
            return x < y;
        return x.size() > y.size();
    }
    
    bool isSubseq(string &str, string &pat)
    {
        int i = 0, j = 0;
        while(i < str.size() && j < pat.size())
        {
            if(str[i] == pat[j])
                j++;
            i++;
        }
        return j == pat.size();
    }
    
    string findLongestWord(string str, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), myComp);
      
        for(int i = 0; i < dictionary.size(); i++)
            if(isSubseq(str, dictionary[i]))
                return dictionary[i];
        return "";
    }
};
