#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::max;
using std::min;

class Solution
{
public:
    string manacherString(string &str)
    {
        string res(str.size()*2+1,' ');
        int index=0;

        for(int i=0;i<res.size();++i)
        {
            res[i]=(i&1)==0?'#':str[index++];
        }

        return res;
    }

    int manacher(string &s)
    {
        if(s.empty())//如果为空我还怎么玩
            return 0;

        string str=manacherString(s);//123-->#1#2#3#
        
        //回文半径数组，存放回文半径的大小
        vector<int> pArr(str.size(),0);
        int R=-1;//中心
        int C=-1;// 讲述：R代表最右的扩成功的位置    代码：最右的扩成功的再下一个位置
        int maxValue=0;// 扩出来的最大值，每次存的是最大的回文半径

        for(int i=0;i<str.size();++i)// 每一个位置都求回文半径
        {
            // i至少的回文区域，先给pArr[i]
			//R>i，代表i在R内,2*C-i就是i'的位置
			//R<=i，则，回文半径至少是1啊，就是本身，中心点位置永远构成回文
			//i位置扩出来的答案，i位置扩的区域至少是多大，
            pArr[i]=i>R?1:min(2*C-i,R-i);

            //这是扩的过程，中2和3直接退出，1和4就扩
			//右边不越界，左边不越界的情况下，就扩
            while(i+pArr[i]<str.size()&&i-pArr[i]>-1)
            {
                if(str[i+pArr[i]]==str[i-pArr[i]])
                    pArr[i]++;//求的是半径加1就行了
                else
                    break;
            }
            
            //看这个位置有没有刷新R
			//R和C是同时更新的
            if(i+pArr[i]>R)
            {
                R=i+pArr[i];
                C=i;
            }

            maxValue=max(maxValue,pArr[i]);
        }

        return maxValue-1;
    }

};

int main()
{
    Solution solut;
    string str="122131221";
    string str1="1221";
    string str2="abcdcbkfefkbcdcba";

    cout<<solut.manacher(str)<<endl;
    cout<<solut.manacher(str1)<<endl;
    cout<<solut.manacher(str2)<<endl;

    return 0;
}

