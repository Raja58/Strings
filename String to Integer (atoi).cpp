// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        03 Dec 2021
//  @Detail  :        String to Integer (atoi) (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int myAtoi(string str) {
        int result = 0, idx = 0;
        while(idx < str.size() && str[idx] == ' ')
            idx++;
        if(idx == str.size())
            return result;
        
        bool isNegative = false;
        if(str[idx] == '-')
        {
            isNegative = true;
            idx++;
        }
        else if(str[idx] == '+')
            idx++;
        if(idx == str.size())
            return result;
        
        if(isNegative)
        {
             while(idx < str.size() && isdigit(str[idx]))
             {
                 if(result < INT_MIN / 10 || (result == INT_MIN / 10 && str[idx] - '0' > 8))
                    return INT_MIN;
                if(result >= 0)
                    result *= -1;
                result = result * 10 - (str[idx] - '0');
                idx++;
             }
        }
        else
        {
            while(idx < str.size() && isdigit(str[idx]))
            {
                if(result > INT_MAX / 10 || (result == INT_MAX / 10 && str[idx] - '0' > 7))
                   return INT_MAX;
                result = result * 10 + (str[idx] - '0');
                idx++;
            }
        }
        return result;
    }
};
