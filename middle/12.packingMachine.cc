#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::max;

class Solution
{
public:
    int packingMachine(vector<int> &vec)
    {
        if(vec.size()==0)
            return 0;

        int len=vec.size();
        int sum=0;

        for(int i=0;i<len;++i)
            sum+=vec[i];

        //每一台机器上放avg个
        int avg=sum/len;
        int res=0;
        int leftSum=0;//左边累加和

        for(int i=0;i<vec.size();++i)
        {
            //i号机器是中间机器，左(0 - i-1) i 右(i+1 - vec.size()-1)
            //负需要输入，正需要输出
            int leftRest=leftSum-i*avg;//a-b
            int rightRest=(sum-leftSum-vec[i])-(len-i-1)*avg;//c-d
            
            //如果往外扔，一次只能扔一个
            if(leftRest<0&&rightRest<0)
                res=max(res,abs(leftRest)+abs(rightRest));
            else
                res=max(res,max(abs(leftRest),abs(rightRest)));

            leftSum+=vec[i];
        }

        return res;
    }
};

int main()
{
    Solution solut;
    int arr[3]={5,0,1};
    vector<int> vec(arr,arr+3);

    cout<<solut.packingMachine(vec)<<endl;

    return 0;
}

