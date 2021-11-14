// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        14 Nov 2021
//  @Detail  :        Add Binary (LeetCode)
//  ============================
//  -->

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() != b.size())
        {
            if(a.size() < b.size())
                swap(a, b);
            string x(a.size() - b.size(), '0');
            b = x + b;
        }
        string result = "";
        bool carry = false;
        for(int i = a.size() - 1; i >= 0; i--)
        {
            if(a[i] == '0' && b[i] == '0')
            {
                if(carry)
                    result = '1' + result, carry = false;
                else
                    result = '0' + result;
            }
            else if(a[i] == '1' && b[i] =='1')
            {
                if(carry)
                    result = '1' + result;
                else
                    result = '0' + result;
                carry = true;
            }
            else
            {
                if(carry)
                    result = '0' + result, carry = true;
                else
                    result = '1' + result;
            }
        }
        if(carry) result = '1' + result;
        return result;
    }
};
