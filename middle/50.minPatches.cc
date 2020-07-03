#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    int minPatches(vector<int> &vec,int K)
    {
        int patches=0;//表示缺多少数字
        long range=0;//已经完成了1~range的目标，用long是为了保证不越界，用long型逼近整型
        
        for(int i=0;i<vec.size();++i)
        {
            while(vec[i]>range+1)
            {
                range+=range+1;//range+1是缺的数字
                ++patches;
                if(range>=K)//range往右扩了就看有没有完成总目标，一旦完成了总目标就返回
                    return patches;
            }

            range+=vec[i];
            if(range>=K)//range往右扩了就看有没有完成总目标，一旦完成了总目标就返回
                return patches;
        }

        //数组中的数我全用了，还是没有完成总目标
        while(K>=range+1)
        {
            range+=range+1;//range+1是缺的数字
            ++patches;
        }

        return patches;
    }
};

int main()
{
    Solution solut;
    int arr[4]={1,2,3,7};
    int arr1[3]={1,5,7};
    vector<int> vec(arr,arr+4);
    vector<int> vec1(arr1,arr1+3);
    int k=15;

    cout<<solut.minPatches(vec,k)<<endl;
    cout<<solut.minPatches(vec1,k)<<endl;


    return 0;
}

