// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        27 Nov 2021
//  @Detail  :        Partition Labels (LeetCode)
//  ============================
//  -->

class Solution {
public:
    vector<int> partitionLabels(string str) {
        vector<int> lastSeen(26), result;
        for(int i = 0; i < str.size(); i++)
            lastSeen[str[i] - 'a'] = i;
        
        int start = 0, end = 0;
        for(int i = 0; i < str.size(); i++)
        {
            end = max(end, lastSeen[str[i] - 'a']);
            if(end == i)
            {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};
