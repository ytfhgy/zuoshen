#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits.h>

using std::cout;
using std::endl;
using std::vector;
using std::max;
using std::min;
using std::unordered_set;

class Solution
{
public:
    bool isIntergrate(vector<int> &vec,int left,int right)
    {
        vector<int> newVec(right-left+1,0);
        int index=0;
        for(int i=left;i<=right;++i)
        {
            newVec[index++]=vec[i];
        }

        sort(newVec.begin(),newVec.end());

        for(int i=1;i<newVec.size();++i)
        {
            if(newVec[i-1]!=newVec[i]-1)
                return false;
        }

        return true;
    }

    int logestIntergrateLength(vector<int> &vec)
    {
        if(vec.size()<2)
            return vec.size();

        int maxLen=0;
        for(int i=0;i<vec.size();++i)
        {
            for(int j=i;j<vec.size();++j)
            {
                if(isIntergrate(vec,i,j))
                {
                    maxLen=max(maxLen,j-i+1);
                }
            }
        }

        return maxLen;
    }

    int logestIntergrateLength1(vector<int> &vec)
    {
        if(vec.size()<2)
            return vec.size();

        int maxLength=0;

        for(int left=0;left<vec.size();++left)
        {
            int maxValue=vec[left];
            int minValue=vec[left];
            unordered_set<int> mySet;

            for(int right=left;right<vec.size();++right)
            {
                if(mySet.find(vec[right])!=mySet.end())
                {
                    break;
                }

                mySet.insert(vec[right]);
                maxValue=max(maxValue,vec[right]);
                minValue=min(minValue,vec[right]);

                if(maxValue-minValue==right-left)
                    maxLength=max(maxLength,maxValue-minValue+1);
            }
        }

        return maxLength;
    }
};

int main()
{
    Solution solut;
    int arr[7]={5,5,3,2,6,4,3};
    vector<int> vec(arr,arr+7);

    cout<<solut.logestIntergrateLength(vec)<<endl;
    cout<<solut.logestIntergrateLength1(vec)<<endl;

    return 0;
}

