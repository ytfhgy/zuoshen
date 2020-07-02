#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution
{
public:
    bool stringCross(string &str1,string &str2,string &aim)
    {
        if(str1.empty()||str2.empty()||aim.empty())
            return false;

        if(str1.size()+str2.size()!=aim.size())
            return false;
        
        //标准的二维尝试模型
        vector<vector<bool>> dp(str1.size()+1,vector<bool>(str2.size()+1,false));
        dp[0][0]=true;

        //初始化最上方
        for(int j=1;j<=str2.size();++j)
        {
            if(aim[j-1]==str2[j-1])
                dp[0][j]=true;
        }

        //初始化最左边
        for(int i=1;i<=str1.size();++i)
        {
            if(aim[i-1]==str1[i-1])
                dp[i][0]=true;
        }

        //初始化剩下的
        for(int i=1;i<=str1.size();++i)
        {
            for(int j=1;j<=str2.size();++j)
            {
                //只要从左边或者上边可以的我就为true
                if((aim[i+j-1]==str1[i-1]&&dp[i-1][j])||(aim[i+j-1]==str2[j-1]&&dp[i][j-1]))
                    dp[i][j]=true;
            }
        }

        return dp[str1.size()][str2.size()];
    }

    //这道题是可以进行空间压缩的
    bool stringCross1(string &str1,string &str2,string &aim)
    {
        if(str1.empty()||str2.empty()||aim.empty())
            return false;
        if(str1.size()+str2.size()!=aim.size())
            return false;
        
        string longStr=str1.size()>=str2.size()?str1:str2;
        string shortStr=longStr==str1?str2:str1;

        vector<bool> dp(shortStr.size()+1,false);
        dp[0]=true;

        //进行初始化
        for(int i=1;i<=shortStr.size();++i)
        {
            if(shortStr[i-1]==aim[i-1])
                dp[i]=true;
        }

        //对剩下的进行初始化
        for(int i=1;i<=longStr.size();++i)
        {
            dp[0]=dp[0]&&longStr[i-1]==aim[i-1];
            for(int j=1;j<=shortStr.size();++j)
            {
                if((dp[j-1]&&shortStr[j-1]==aim[i+j-1])||(dp[j]&&longStr[i-1]==aim[i+j-1]))
                    dp[j]=true;
            }
        }
        
        return dp[shortStr.size()];
    }
};

int main()
{
    Solution solut;
    string str1="abbc";
    string str2="bbcd";
    string aim="abbbcbcd";

    cout<<solut.stringCross(str1,str2,aim)<<endl;
    cout<<solut.stringCross1(str1,str2,aim)<<endl;

    return 0;
}

