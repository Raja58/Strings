// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        28 Dec 2021
//  @Detail  :        Integer to English Words (LeetCode)
//  ============================
//  -->

class Solution {
public:
    vector<string> below20{"", "One", "Two", "Three", "Four", "Five", 
                           "Six", "Seven", "Eight", "Nine", "Ten",
                           "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", 
                           "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> below100{"", "", "Twenty", "Thirty", "Forty", "Fifty", 
                           "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string getWord(int num)
    {
        if(num >= 1e9)
            return getWord(num / (int)(1e9)) + " Billion" + getWord(num % (int)(1e9));
        else if(num >= 1e6)
            return getWord(num / (int)(1e6)) + " Million" + getWord(num % (int)(1e6));
        else if(num >= 1000)
            return getWord(num / 1000) + " Thousand" + getWord(num % 1000);
        else if(num >= 100)
            return getWord(num / 100) + " Hundred" + getWord(num % 100);
        else if(num >= 20)
            return " " + below100[num / 10] + getWord(num % 10);
        else if(num >= 1)
            return " " + below20[num];
        return "";
    }
    
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        return getWord(num).substr(1);
    }
};
