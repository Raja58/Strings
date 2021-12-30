// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        30 Dec 2021
//  @Detail  :        Backspace String Compare (LeetCode)
//  ============================
//  -->

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sIdx = s.size() - 1, tIdx = t.size() - 1;
        int sHashCnt = 0, tHashCnt = 0;
        while(sIdx >= 0 || tIdx >= 0)
        {
            while(sIdx >= 0)
            {
                if(s[sIdx] == '#')
                    sHashCnt++;
                else if(sHashCnt > 0)
                    sHashCnt--;
                else
                    break;
                sIdx--;
            }
            
            while(tIdx >= 0)
            {
                if(t[tIdx] == '#')
                    tHashCnt++;
                else if(tHashCnt > 0)
                    tHashCnt--;
                else
                    break;
                tIdx--;
            }
            
            if(sIdx >= 0 && tIdx >= 0)
            {
                if(s[sIdx] != t[tIdx])
                    return false;
                sIdx--; tIdx--;
            }
            else if((sIdx < 0 && tIdx >= 0) || (sIdx >= 0 && tIdx < 0))
                return false;
        }
        return true;
    }
};
