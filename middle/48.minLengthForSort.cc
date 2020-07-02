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
    int minLengthForSort(vector<int> &vec)
    {
        if(vec.size()<2)
            return 0;

        int maxIndex=vec[0];
        int indexRight=0;

        //从左往右，找到最后一个不达标的位置
        for(int i=1;i<vec.size();++i)
        {
            if(vec[i]<maxIndex)
            {
                indexRight=i;
            }

            maxIndex=max(maxIndex,vec[i]);
        }

        int minIndex=vec[vec.size()-1];
        int indexLeft=0;
        //从右往左，找到最后一个不达标的位置
        for(int i=vec.size()-2;i>=0;--i)
        {
            if(vec[i]>minIndex)
            {
                indexLeft=i;
            }

            minIndex=min(minIndex,vec[i]);
        }
        
        return indexRight-indexLeft+1;
    }
};

int main()
{
    Solution solut;
    int arr[9]={1,2,5,4,2,7,6,8,9};
    vector<int> vec(arr,arr+9);

    cout<<solut.minLengthForSort(vec)<<endl;

    return 0;
}

