#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::max;

class Solution
{
public:
    int subArrayMaxSum(vector<int> &vec)
    {
        if(vec.empty())
            return 0;

        int cur=0;//当前累加和
        int maxSum=0;//最大子数组累加和

        for(int i=0;i<vec.size();++i)
        {
            cur+=vec[i];
            maxSum=max(maxSum,cur);
            cur=cur<0?0:cur;
        }

        return maxSum;
    }

    void printVector(vector<int> &vec)
    {
        for(auto it:vec)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }


};

int main()
{
    int arr[8]={-3,-2,-5,40,-10,-10,100,1};
    int arr1[7]={-2,-3,-5,0,1,2,-1}; 
    int arr2[4]={-2,-3,-5,-1};
    vector<int> vec(8,0);
    vector<int> vec1(7,0);
    vector<int> vec2(4,0);

    for(int i=0;i<8;++i)
    {
        vec[i]=arr[i];
    }

    for(int i=0;i<7;++i)
    {
        vec1[i]=arr1[i];
    }

    for(int i=0;i<4;++i)
    {
        vec2[i]=arr2[i];
    }

    Solution solut;

    solut.printVector(vec);
    cout<<solut.subArrayMaxSum(vec)<<endl;
    cout<<endl;
    solut.printVector(vec1);
    cout<<solut.subArrayMaxSum(vec1)<<endl;
    cout<<endl;
    solut.printVector(vec2);
    cout<<solut.subArrayMaxSum(vec2)<<endl;
    cout<<endl;

    return 0;
}

