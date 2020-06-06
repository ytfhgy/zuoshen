#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::max;

class Solution
{
public:
    vector<vector<int>> getdp(string &str1,string &str2)
    {
        int row=str1.size();
        int colum=str2.size();
        vector<vector<int>> dp(row,vector<int>(colum,0));

        //进行初始化
        dp[0][0]=str1[0]==str2[0];
        
        //对最上方进行初始化
        for(int i=1;i<row;++i)
        {
            dp[0][i]=dp[0][i-1]+(str1[0]==str2[i]);
        }

        //对最左方进行初始化
        for(int i=1;i<row;++i)
        {
            dp[i][0]=dp[i-1][0]+(str1[i]==str2[0]);
        }

        //对剩下的进行填写
        for(int i=1;i<row;++i)
        {
            for(int j=1;j<colum;++j)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(str1[i]==str2[j])
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        }

        return dp;
    }

    string LCSubSequence(string &str1,string &str2)
    {
        if(str1.empty()||str2.empty())
            return " ";
        
        int N=str1.size()-1;
        int M=str2.size()-1;
        vector<vector<int>> dp=getdp(str1,str2);

        //要找到最长的公共子序列，要从dp的最右下角开始往回蹦
        string res(dp[N][M],' ');
        int index=res.size()-1;//表示结果string的索引

        while(index>=0)
        {
           if(N>0&&dp[N-1][M]==dp[N][M])
           {
                --N;
           }else if(M>0&&dp[N][M-1]==dp[N][M])
           {
               --M;
           }else
           {
               res[index--]=str1[N];
               --N;
               --M;
           }
        }

        return res;

    }
};

int main()
{
    Solution solut;
    string str1="ab12c34de5f";
    string str2="g12hi345XYZ";

    cout<<solut.LCSubSequence(str1,str2)<<endl;

    return 0;
}

