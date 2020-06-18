#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

bool comp(const vector<int> &a,const vector<int> &b)
{
    if(a[0]!=b[0])
        return a[0]<b[0];
    else
        return a[1]>b[1];
}

class Solution
{
public:
    int envelopesProblem(vector<vector<int>> &matrix,int n)
    {
        sort(matrix.begin(),matrix.end(),comp);

        vector<int> dp(n,0);
        vector<int> ends(n,0);

        dp[0]=1;
        ends[0]=matrix[0][1];
        
        int left=0;
        int right=0;
        int temp=0;

        for(int index=1;index<n;++index)
        {
            left=0;
            right=temp;
            
            //使用二分查找在enss中第一个比matrix[index][1]大的数
            while(left<=right)
            {
                int mid=left+((right-left)>>1);
                if(matrix[index][1]>ends[mid])
                    left=mid+1;
                else
                    right=mid-1;
            }

            temp=temp>left?temp:left;//看能不能更新右边界
            ends[left]=matrix[index][1];
            dp[index]=left+1;
        }

        int maxValue=0;
        for(int index=0;index<n;++index)
        {
            maxValue=maxValue>dp[index]?maxValue:dp[index];
        }

        return maxValue;
    }

};

int main()
{
    int n;

    cin>>n;

    vector<vector<int>> matrix(n,vector<int>(2,0));

    for(int i=0;i<n;++i)
    {
        cin>>matrix[i][0]>>matrix[i][1];
    }

    Solution solut;
    cout<<"可以嵌套"<<solut.envelopesProblem(matrix,n)<<"层"<<endl;;

    return 0;
}

