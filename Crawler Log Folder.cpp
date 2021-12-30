// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        30 Dec 2021
//  @Detail  :        Crawler Log Folder (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0, result = 0;
        for(int i = logs.size() - 1; i >= 0; i--)
        {
            if(logs[i] == "../")
                cnt++;
            else if(logs[i] != "./")
            {
                if(cnt > 0)
                    cnt--;
                else
                    result++;
            }
        }
        return result;
    }
};
