#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::max;

class Solution
{
public:
    int jumpGame(vector<int> &vec)
    {
        if(vec.size()<1)
            return 0;

        int step=0;//跳了多少步/现在蹦了几次一步
        int cur=0;//jump步内，右边界/如果不增加步数你能到哪
        int next=0;//step+1步内，右边界/如果再增加一步，你右边最远到哪

        for(int i=0;i<vec.size();++i)
        {
            if(cur<i)//必须要走一步了
            {
                ++step;
                cur=next;
            }

            next=max(next,i+vec[i]);
        }

        return step;
    }
};

int main()
{
    Solution solut;
    int arr[11]={3,6,1,1,1,1,1,9,1,1,1};
    vector<int> vec(arr,arr+11);

    cout<<solut.jumpGame(vec)<<endl;

    return 0;
}

