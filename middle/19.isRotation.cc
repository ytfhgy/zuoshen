#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution
{
public:
    //获得nextVector
    vector<int> getNextVector(string &str2)
    {
        vector<int> next(str2.size(),-1);
        if(str2.size()==1)
            return next;
        
        //人为规定index=0时为-1，index=1时为0
        next[0]=-1;
        next[1]=0;

        int index=2;//索引下标从2开始
        int cent=0;//代表当前哪个位置的字符与index-1的位置比较
        
        while(index<str2.size())
        {
            if(str2[index]==str2[cent])
            {
                cent++;
                next[index++]=cent;
            }else if(cent>0)//当前跳到cent位置的字符与index-1位置的字符匹配不上
            {
                //如果cemt不等于-1，可以继续往前跳
                cent=next[cent];
            }else
            {
                next[index++]=0;
            }
        }

        return next;
            
    }

    int getIndex(string &str1,string &str2)
    {
        if(str2.size()>str1.size())
            return -1;

        vector<int> nextVector=getNextVector(str2);

        int index1=0;
        int index2=0;

        while(index1<str1.size()&&index2<str2.size())
        {
            if(str1[index1]==str2[index2])
            {
                ++index1;
                ++index2;
            }else if(nextVector[index2]!=-1)//nextVector[index2]不是-1，可以继续往前跳
            {
                index2=nextVector[index2];
            }else{//已经不能再往前跳了,只能index++;
                ++index1;
            }
        }
        
        return (index2==str2.size())?index1-index2:-1;
    }
    
    bool isRotation(string &str1,string &str2)
    {
        if(str1.empty()||str2.empty()||str1.size()!=str2.size())
            return false;
        
        string str=str1+str1;

        int index=getIndex(str,str2);

        return index!=-1;
    }
};

int main()
{
    Solution solut;

    string s1="cdab";
    string s2="abcd";

    string s3="1ab2";
    string s4="ab12";

    string s5="2ab1";
    string s6="ab12";

    cout<<solut.isRotation(s1,s2)<<endl;
    cout<<solut.isRotation(s3,s4)<<endl;
    cout<<solut.isRotation(s5,s6)<<endl;

    return 0;
}

