// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        07 Sep 2021
//  @Detail  :        Page Overlap (Microsoft)
//  ============================
//  -->

#include <bits/stdc++.h>
using namespace std;

vector<int> getPrefix(string &str)
{
    vector<int> prefix(str.size());
    int len = 0, i = 1;
    while(i < str.size())
    {
        if(str[i] == str[len])
        {
            len++;
            prefix[i] = len;
            i++;
        }
        else if(len == 0)
        {
            prefix[i] = 0;
            i++;
        }
        else
            len = prefix[len - 1];
    }
    return prefix;
}

int knuthMorrisPratt(string &first, string &second)
{
    vector<int> prefix = getPrefix(second);
    int i = 0, j = 0;
    while(i < first.size())
    {
        if(first[i] == second[j])
        {
            i++;
            j++;
        }

        if(i == first.size())
            return j;
        if(first[i] != second[j])
        {
            if(j == 0)
                i++;
            else
                j = prefix[j - 1];
        }
    }
    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    vector<string> firstPage{"aaa", "bbb", "ccc"}, secondPage{"bbb", "ccc", "ddd"};
    string first, second;

    for(int i = 0; i < firstPage.size(); i++)
        first = first + firstPage[i] + '-';
    first.pop_back();

    for(int i = 0; i < secondPage.size(); i++)
        second = second + secondPage[i] + '-';
    second.pop_back();
    
    int length = knuthMorrisPratt(first, second);
    int result = 0, count = 0;

    while(count < length)
    {
        if(count + secondPage[result].size() <= length)
        {
            count += secondPage[result].size();
            result++;
        }
        
        if(count == length)
            break;
        else
            count++;
    }

    cout<<"Maximum Overlap : "<<result<<"\n";
    
    for(int i = 0; i < result; i++)
        cout<<secondPage[i]<<"\n";
        
    return 0;
}
