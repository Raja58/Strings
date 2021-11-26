// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        26 Nov 2021
//  @Detail  :        Minimum Length of String After Deleting Similar Ends (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int minimumLength(string str) {
        int i = 0, j = str.size() - 1;
        vector<int> result{i, j};
        while(i < j)
        {
            if(str[i] != str[j])
                return result[1] - result[0] + 1;
            char c = str[i];
            while(i < j && str[i + 1] == c)
                i++;
            while(j > i && str[j - 1] == c)
                j--;
            if(i >= j)
                return 0;
            i++;    j--;
            result = {i, j};
        }
        return 1;
    }
};
