// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        20 Nov 2021
//  @Detail  :        Restore IP Addresses (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    bool isValid(string x)
    {
        if(x.size() == 1)
            return true;
        if(x[0] == '0')
            return false;
        return stoll(x) <= 255;
    }
    
    vector<string> restoreIpAddresses(string str) {
        int n = str.size();
        vector<string> result;
        if(n < 4)
            return result;
        
        for(int i = 0; i < n - 3; i++)
        {
            if(!isValid(str.substr(0, i + 1)))
                continue;
            string a = str.substr(0, i + 1) + '.';
            for(int j = i + 1; j < n - 2; j++)
            {
                if(!isValid(str.substr(i + 1, j - i)))
                    continue;
                string b = str.substr(i + 1, j - i) + '.';
                for(int k = j + 1; k < n - 1; k++)
                {
                    if(!isValid(str.substr(j + 1, k - j)))
                        continue;
                    string c = str.substr(j + 1, k - j) + '.';
                    if(!isValid(str.substr(k + 1)))
                        continue;
                    string d = str.substr(k + 1);
                    result.push_back(a + b + c + d);
                }
            }
        }
        return result;
    }
};
