#include <iostream>
#include <string>
#include <climits>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::min;
using std::vector;

class Solution
{
public:
    //求s2到s1Sub的编辑距离
    //假设编辑距离只有删除动作且删除一个字符的代价为1
    int distance(string &s2,string &s1Sub)
    {
        int row=s2.size();
        int colum=s1Sub.size();
        vector<vector<int>> dp(row,vector<int>(colum,0));

        //dp[i][j]的含义：
        //s2[0...i]仅通过删除行为变成s1Sub[0...j]的最小代价
        //可能性一:
        //s2[0...i]变的过程中，不保留最后一个字符（s2[i]）
        //那么就是通过s2[0...i-1]变成s1Sub[0...j]之后，最后再删掉s2[i]
        //即 ->dp[i][j]=dp[i-1][j]+1
        //
        //可能性二
        //s2[0...i]变的过程中，想保留最后一个字符（s2[i]）,然后变成s1Sub[0...j]
        //这也要求s2[i]==s1Sub[j]才有这种可能，然后s2[0...i-1]变成s1Sub[0...j-1]即可
        //也就是s2[i]==s1Sub[j]的条件下，dp[i][j]=dp[i-1][j-1]
        dp[0][0]=s2[0]==s1Sub[0]?0:INT_MAX;

        //先初始化最上方
        for(int j=1;j<colum;++j)
        {
            dp[0][j]=INT_MAX;
        }
        
        //初始化最左边
        for(int i=1;i<row;++i)
        {
            dp[i][0]=(dp[i-1][0]!=INT_MAX||s2[i]==s1Sub[0])?i:INT_MAX;
        }

        for(int i=1;i<row;++i)
        {
            for(int j=1;j<colum;++j)
            {
                dp[i][j]=INT_MAX;
                if(dp[i-1][j]!=INT_MAX)
                    dp[i][j]=dp[i-1][j]+1;
                if(s2[i]==s1Sub[j]&&dp[i-1][j-1]!=INT_MAX)
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            }
        }

        return dp[row-1][colum-1];
    }
    
    //生成s1的所有子串
    //然后考察每个子串和s2的编辑距离(假设编辑距离只有删除动作并且删除一个字符的代价为1)
    //如果s1的长度较小，s2的长度较大，这个方法比较合适
    int deleteMinCost(string &s1,string &s2)
    {
        int res=INT_MAX;
        for(int start=0;start<s1.size();++start)
        {
            for(int end=start+1;end<=s1.size();++end)
            {
                string s1Sub=s1.substr(start,end);
                res=min(res,distance(s2,s1Sub));
            }
        }

        return res;
    }

};

int main()
{
    Solution solut;
    string s1="abcde";
    string s2="axbc";

    cout<<solut.deleteMinCost(s1,s2)<<endl;

    return 0;
}
