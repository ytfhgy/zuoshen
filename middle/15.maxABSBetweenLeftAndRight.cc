#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::max;

class Solution
{
public:
    int maxABSBetweenLeftAndRight(vector<int> &vec)
    {
        //先求出整体的最大值
        int sumValue=0;
        for(int i=0;i<vec.size();++i)
            sumValue=max(sumValue,vec[i]);
        
        //两头谁小减谁
        return sumValue-(vec[0]>vec[vec.size()-1]?vec[vec.size()-1]:vec[0]);
    }
};

int main()
{
    int arr[7]={3,5,2,4,6,7,3};
    vector<int> vec(arr,arr+7);
    Solution Solut;

    cout<<Solut.maxABSBetweenLeftAndRight(vec)<<endl;

    return 0;
}

