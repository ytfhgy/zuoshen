#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::min;
using std::unordered_set;

class Solution
{
public:
    //标准的从左到右尝试模型
    void process(vector<int> &vec,int index,int sum,unordered_set<int> &mySet)
    {
        if(index==vec.size())
        {
            mySet.insert(sum);
            return;
        }
        
        //每止一次我都可以选择要或者不要
        process(vec,index+1,sum,mySet);//我不要
        process(vec,index+1,sum+vec[index],mySet);//我要
    }

    int smallestUnformeSum1(vector<int> &vec)
    {
        if(vec.empty())
            return 1;

        unordered_set<int> mySet;
        process(vec,0,0,mySet);
        int minValue=vec[0];
        int sum=vec[0];
        for(int i=1;i<vec.size();++i)
        {
            minValue=min(minValue,vec[i]);
            sum+=vec[i];
        }

        for(int i=minValue;i<=sum;++i)
        {
            if(mySet.find(i)==mySet.end())//如果不在mySet里，则必然是最小不可组成和
            {
                return i;
            }
        }
        
        return sum+1;
    }

    //使用动态规划，用二维表
    int smallestUnformeSumdp(vector<int> &vec)
    {   
        if(vec.size()==0)
            return 1;
        
        int minValue=vec[0];
        int sumValue=vec[0];

        //先找出最大的和最小的
        for(int i=1;i<vec.size();++i)
        {
            minValue=min(minValue,vec[i]);
            sumValue+=vec[i];
        }
        
        vector<vector<bool>> dp(vec.size(),vector<bool>(sumValue+1,false));
        dp[0][0]=true;

        //先初始化第一列
        for(int i=1;i<vec.size();++i)//其实第一列全为true
        {
           dp[i][0]=true; 
        }
        
        //初始化第一行
        for(int i=1;i<=sumValue;++i)
        {
            if(i==vec[0])
                dp[0][i]=true;
        }

        //初始化剩下的
        for(int i=1;i<vec.size();++i)
        {
            for(int j=1;j<=sumValue;++j)
            {
                dp[i][j]=dp[i-1][j];//我不要
                if(j-vec[i]>=0)//我不要
                    dp[i][j]=dp[i][j]||dp[i-1][j-vec[i]];
            }
        }

        //查看dp的最后一行哪个为true
        for(int i=minValue;i<=sumValue;++i)
        {
            if(!dp[vec.size()-1][i])
                return i;
        }
        
        //如果都能达到，则为sumValue+1
        return sumValue+1;
    }

    //使用动态规划可以将二维表压缩为一维的
    int smallestUnformeSumdp1(vector<int> &vec)
    {
        if(vec.size()==0)
            return 1;

        //先找出最大的和最小的
        int minValue=vec[0];
        int sumValue=vec[0];

        for(int i=1;i<vec.size();++i)
        {
            minValue=min(minValue,vec[i]);
            sumValue+=vec[i];
        }

        vector<bool> dp(sumValue+1,false);
        dp[0]=true;

        for(int i=0;i<vec.size();++i)
        {
            for(int j=sumValue;j>=vec[i];--j)
            {
                //每次我可以选择要或者不要
                dp[j]=dp[j-vec[i]]?true:dp[j];
            }
        }

        for(int i=minValue;i<dp.size();++i)
        {
            if(!dp[i])//查看哪个为false即为所求
                return i;
        }

        //如果都能达到，则为sumValue+1
        return sumValue+1;
    }

    //如果数组中一定存在1
    int smallestUnformeSum2(vector<int> &vec)
    {
        if(vec.size()==0)
            return 1;
        
        //先进行排序
        std::sort(vec.begin(),vec.end());

        int range=1;
        for(int i=1;i<vec.size();++i)
        {
            if(vec[i]<=range)
                range+=vec[i];//扩大往右扩的范围
            else
                return range+1;//一旦超了，则直接返回range+1
        }

        return range+1;//如果所有的东西都能搞定，则返回range+1
    }
}; 

int main()
{
    Solution solut;
    int arr[3]={3,2,5};
    int arr1[3]={1,3,8};
    vector<int> vec(arr,arr+3);
    vector<int> vec1(arr,arr+3);

    cout<<solut.smallestUnformeSum1(vec)<<endl;
    cout<<solut.smallestUnformeSumdp(vec)<<endl;
    cout<<solut.smallestUnformeSumdp1(vec)<<endl;
    cout<<solut.smallestUnformeSum2(vec1)<<endl;

    return 0;
}

