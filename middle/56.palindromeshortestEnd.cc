#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::min;

class Solution
{
public:
    string strManacher(string &str)
    {
        string res(2*str.size()+1,' ');
        int index=0;

        for(int i=0;i<res.size();++i)
        {
            res[i]=(i&1)==0?'#':str[index++];
        }

        return res;
    }

    string palindromeshortestEnd(string &s)
    {
        if(s.empty())//这让我怎么玩
            return " ";

        string str=strManacher(s);

        //回文半径的数组，存放的是每一个字符回文半径的大小
        vector<int> pArr(str.size(),0);
        int R=-1;//代表最右的扩成功的下一个位置
        int C=-1;//中心
        int maxContaionsEnd=0;//存放最长的回文串

        for(int index=0;index<str.size();++index)
        {

            //i至少的回文区域，先给pArr[i]  
            //R>i，代表i在R内,2*C-i就是i'的位置  
            //R<=i，则，回文半径至少是1啊，就是本身，中心点位置永远构成回文  
            //i位置扩出来的答案，i位置扩的区域至少是多大，
            pArr[index]=index>=R?1:min(R-index,index-pArr[index]);

            //这是扩的过程，中2和3直接退出，1和4就扩  
            //右边不越界，左边不越界的情况下，就扩
            while(index+pArr[index]<str.size()&&index-pArr[2*C-index]>-1)
            {
                if(str[index+pArr[index]]==str[index-pArr[index]])
                {
                    pArr[index]++;//求的是半径加1就行了
                }else
                {
                    break;
                }
            }


            //看这个位置有没有刷新R  
            //R和C是同时更新的
            if(index+pArr[index]>R)
            {
                R=index+pArr[index];
                C=index;
            }

            if(R==str.size())
            {
                maxContaionsEnd=pArr[index];
                break;
            }
        }

        string res(s.size()-maxContaionsEnd+1,' ');

        for(int i=0;i<res.size();++i)
        {
            res[res.size()-1-i]=str[i*2+1];
        }

        return res;
    }

};

int main()
{
    Solution solut;
    string str="abcd123321";
    cout<< solut.palindromeshortestEnd(str)<<endl;

    return 0;
}

