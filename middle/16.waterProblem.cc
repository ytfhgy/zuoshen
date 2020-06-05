#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::max;
using std::min;

class Solution
{
public:
    //这里的时间复杂度为O(N*N)
    int waterProblem1(vector<int> &vec)
    {
        if(vec.size()<3)
            return 0;

        int mostWater=0;
        for(int i=1;i<vec.size()-1;++i)
        {
            int leftMax=0;
            int rightMax=0;
            
            //每一次以i为分界
            //找出左边部分的最大值
            for(int l=0;l<i;++l)
                leftMax=max(leftMax,vec[l]);  
            
            //找出右边部分的最大值
            for(int r=i+1;r<vec.size();++r)
                rightMax=max(rightMax,vec[r]);

            mostWater+=max(0,min(leftMax,rightMax)-vec[i]);
        }

        return mostWater;
    }
    
    //这里的时间复杂度为O(1)
    int waterProblem2(vector<int> &vec)
    {
        if(vec.size()<3)
            return 0;

        int leftMax=vec[0];
        int rightMax=vec[vec.size()-1];
        int left=1;
        int right=vec.size()-2;
        int mostWater=0;

        while(left<=right)
        {
           //谁小先算谁的
           if(leftMax<rightMax)
           {
               mostWater+=max(0,leftMax-vec[left]);
               leftMax=leftMax<vec[left]?vec[left]:leftMax;
               ++left;
           }else
           {
                mostWater+=max(0,rightMax-vec[right]);
                rightMax=rightMax<vec[right]?vec[right]:rightMax;
                --right;
           }
        }

        return mostWater;
    }

};

int main()
{
    Solution solut;

    int arr[5]={3,5,1,2,4};
    vector<int> vec(arr,arr+5);

    cout<<solut.waterProblem1(vec)<<endl;
    cout<<solut.waterProblem2(vec)<<endl;

    return 0;
}

