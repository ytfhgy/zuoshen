#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    //标准的从左到右尝试模型
    int process(vector<int> &vec,int index,int rest)
    {
        //base case
        if(rest<0)//表示没有容量了
            return -1;//-1表示无方案

        //默认rest>=0
        if(index==vec.size())//无零售可选了就是一种方案
            return 1;
        
        //index号零食 要or不要
        //res1不可能是-1，因为我的零售没有变
        int res1=process(vec,index+1,rest);//不要当前的零食
        int res2=process(vec,index+1,rest-vec[index]);//要当前的零食

        return res1+(res2==-1?0:res2);
    }

    int snacksWays(vector<int> &vec,int weight)
    {
        return process(vec,0,weight);
    }

    int snacksWaysdp(vector<int> &vec,int weight)
    {
        int N=vec.size()+1;
        int M=weight+1;

        vector<vector<int>> dp(N,vector<int>(M,0));

        //根据暴力递归中的base case进行初始化
        for(int i=0;i<M;++i)
        {
            dp[N-1][i]=1;
        }

        for(int i=N-2;i>=0;--i)
        {
            for(int j=0;j<M;++j)
            {
                dp[i][j]=dp[i+1][j]+(j-vec[i]>=0?dp[i+1][j-vec[i]]:0);
            }
        }

        return dp[0][M-1];
    }
};

int main()
{
    Solution solut;
    int arr[4]={4,3,2,9};
    int weight=8;
    vector<int> vec(arr,arr+4);

    cout<<solut.snacksWays(vec,weight)<<endl;
    cout<<solut.snacksWaysdp(vec,weight)<<endl;

    return 0;
}

