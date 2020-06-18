#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::min;

class Solution
{
public:
    int editCost(string &str1,string &str2,int ic,int dc,int rc)
    {
        if(str1.empty()||str2.empty())
            return 0;

        int n=str1.size()+1;//str1的长度作为行
        int m=str2.size()+1;//str2的长度作为列

        vector<vector<int>> dp(n,vector<int>(m,0));

        //初始化最上方，进行插入
        for(int i=1;i<m;++i)
        {
            dp[0][i]=i*ic;
        }

        //初始化最左方，进行删除
        for(int i=1;i<n;++i)
        {
            dp[i][0]=dc*i;
        }

        //填补剩下的
        for(int i=1;i<n;++i)
        {
            for(int j=1;j<m;++j)
            {
                if(str1[i-1]==str2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=dp[i-1][j-1]+rc;

                dp[i][j]=min(dp[i][j],dp[i-1][j]+dc);
                dp[i][j]=min(dp[i][j],dp[i][j-1]+ic);
            }
        }

        return dp[n-1][m-1];
    }
    
    //因为只跟其左边，左上角、右下角有关，所以可以进行空间压缩
    int editCost1(string &s1,string &s2,int ic,int dc,int rc)
    {
        if(s1.empty()||s2.empty())
            return 0;
        string s=s1;

        s1=s1.size()>s2.size()?s:s2;
        s2=s1==s?s2:s;

        int n=s1.size();//长的字符串作为行
        int m=s2.size();//短的字符串作为列
        vector<int> dp(m+1,0);

        //先初始化第一行，进行插入
        for(int i=1;i<=m;++i)
        {
            dp[i]=i*ic;
        }

        for(int i=1;i<=n;++i)
        {
            int pre=dp[0];
            dp[0]=i*dc;

            for(int j=1;j<=m;++j)
            {
                int temp=dp[j];
                if(s1[i-1]==s2[j-1])
                    dp[j]=pre;
                else
                    dp[j]=pre+rc;

                dp[j]=min(dp[j],dp[j-1]+ic);
                dp[j]=min(dp[j],temp+dc);
                pre=temp;
            }
        }

        return dp[m];
    }
};


int main()
{
    Solution solut;

    string s1="ab12cd3";
    string s2="abcdf";

    cout<<solut.editCost(s1,s2,5,3,2)<<endl;
    cout<<solut.editCost1(s1,s2,5,3,2)<<endl;

    return 0;
}

