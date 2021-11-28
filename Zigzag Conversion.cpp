// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        28 Nov 2021
//  @Detail  :        Zigzag Conversion (LeetCode)
//  ============================
//  -->

class Solution {
public:
    string convert(string str, int numRows) {
        if(numRows == 1)
            return str;
        
        string result = "";
        int cycle = 2 * numRows - 2;
        for(int row = 0; row < numRows; row++)
        {
            for(int i = row; i < str.size(); i += cycle)
            {
                result = result + str[i];
                if(row == 0 || row == numRows - 1)
                    continue;
                int secondIdx = (i - row) + (cycle - row);
                if(secondIdx < str.size())
                    result = result + str[secondIdx];
            }
        }
        return result;
    }
};
