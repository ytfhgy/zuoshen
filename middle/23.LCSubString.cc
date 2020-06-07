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
    vector<vector<int>> getdp(string &str1,string &str2)
    {
        int N=str1.size();
        int M=str2.size();

        vector<vector<int>> dp(N,vector<int>(M,0));

        //进行初始化
        dp[0][0]=str1[0]==str2[0];

        //对最上方进行初始化
        for(int i=1;i<M;++i)
        {
            if(str1[0]==str2[i])
                dp[0][i]=1;
        }
        
        //对最左方进行初始化
        for(int i=1;i<N;++i)
        {
            if(str1[i]==str2[0])
                dp[i][0]=1;
        }

        //对剩下的进行计算
        for(int i=1;i<N;++i)
        {
            for(int j=1;j<M;++j)
            {
                //如果相等让它等于左上角加1，否则为0
                if(str1[i]==str2[j])
                    dp[i][j]=dp[i-1][j-1]+1;
            }
        }

        return dp;
    }

    string LCSubString(string &str1,string &str2)
    {
        if(str1.empty()||str2.empty())
            return " ";

        vector<vector<int>> dp=getdp(str1,str2);
        
        int N=str1.size();//行
        int M=str2.size();//列
        int end=0;
        int maxValue=0;

        //找到dp里最大的值
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<M;++j)
            {
                if(dp[i][j]>maxValue)
                {
                    maxValue=dp[i][j];
                    end=i;     
                }
            }
        }

        return str1.substr(end-maxValue+1,maxValue);
    }

    //可以进行空间压缩，压缩为空间O(1)
    string LCSubString1(string &str1,string &str2)
    {
        if(str1.empty()||str2.empty())
            return " ";

        int row=0;//行
        int colum=str2.size()-1;

        int end=0;
        int len=0;
        int maxValue=0;

        while(row<str1.size())
        {
            int i=row;
            int j=colum;
            
            //右下方fhu
            while(i<str1.size()&&j<str2.size())
            {
                if(str1[i]==str2[j])
                {
                    ++len;
                }else{
                    len=0;
                }

                if(maxValue<len)
                {
                    maxValue=len;;
                    end=i;
                }
                
                ++i;
                ++j;
            }
            
            //往左到不能往左就往下
            if(colum>0)
            {
                --colum;
            }else{
                ++row;
            }
        }

        return str1.substr(end-maxValue+1,maxValue);
    }
};

int main()
{
    Solution solut;
    string str1="abc12345def";
    string str2="xyz1234pq5";

    cout<<solut.LCSubString(str1,str2)<<endl;
    cout<<solut.LCSubString1(str1,str2)<<endl;

    return 0;
}

