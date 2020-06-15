#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

//最长递增子序列问题
class Solution
{
public:
    vector<int> getdp(vector<int> &vec)
    {
        int N=vec.size();
        vector<int> dp(N,0);
        vector<int> ends(N,0);

        dp[0]=1;
        ends[0]=vec[0];
        int left=0;
        int right=0;
        int temp=0;

        for(int index=1;index<N;++index)
        {
            left=0;
            right=temp;
            
            //采用二分法进行查找
            while(left<=right)
            {
                int mid=left+((right-left)>>1);
                if(vec[index]>ends[mid])
                    left=mid+1;
                else
                    right=mid-1;
            }

            temp=temp>left?temp:left;//用来更新ends边界的
            ends[left]=vec[index];
            dp[index]=left+1;
        }

        return dp;
    }

    vector<int> generateLIS(vector<int> &vec,vector<int> &dp)
    {
        int len=0;
        int index=0;
    
        //下面的for循环找出最长递增子序列的长度
        for(int i=0;i<dp.size();++i)
        {
            if(dp[i]>=len)
            {
                len=dp[i];
                index=i;
            }
        }

        vector<int> res(len,0);
        res[--len]=vec[index];
        
        //逆序找到最长递增子序列
        for(int i=index;i>=0;--i)
        {
            //只有比当前值小并且在dp数组中刚好是后一个数-1的值
            if(vec[i]<vec[index]&&dp[i]==dp[index]-1)
            {
                res[--len]=vec[i];
                index=i;
            }
        }

        return res;
    }

    vector<int> getLIS(vector<int> &vec)
    {
        if(vec.empty())
            return vector<int> (0,0);

        vector<int> dp=getdp(vec);
        vector<int> res=generateLIS(vec,dp);
    
        return res;
    }
};

int main()
{
    Solution solut;
    int arr[8]={4,1,9,2,0,3,100,4};
    vector<int> vec(8,0);

    for(int i=0;i<8;++i)
    {
        vec[i]=arr[i];
    }

    vector<int> res=solut.getLIS(vec);
    for(auto it:res)
    {
        cout<<it<<" ";
    }

    cout<<endl;

    return 0;
}

