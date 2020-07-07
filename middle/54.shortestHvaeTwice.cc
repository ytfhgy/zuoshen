#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution
{
public:
    //这其实就是KMP算法中的next数组
    int endNextLen(string &str)
    {
        vector<int> next(str.size()+1,0);
        
        next[0]=-1;//人为规定为-1
        next[1]=0;//人为规定为0
        int index=2;
        int cen=0;

        while(index<next.size())
        {
            if(str[index-1]==str[cen])
            {
                next[index++]=++cen;
            }else if(cen>0)
            {
                cen=next[cen];//往回跳到不能再往回跳为止
            }
            else
            {
                next[index++]=0;//如果往回跳到不能再往回跳还是没有匹配，则置为0
            }
        }
        
        return next[next.size()-1];
    }

    string shortestHaveTwice(string &str)
    {
        if(str.empty())//如果为空，我还怎么玩
            return " ";

        if(str.size()==1)
            return str+str;

        if(str.size()==2)
            return str[0]==str[1]?str+str[0]:str+str;

        int endNext=endNextLen(str);

        return str+str.substr(endNext);//单个参数则默认拷贝从第endNext位开始至末尾的字符串
    }
};

int main()
{
    Solution solut;
    string str="123123";
    string str1="abcd";
    string str2="aa";
    string str3="a";
    string str4="ab";
    string str5="abracadabra";

    cout<<solut.shortestHaveTwice(str)<<endl;
    cout<<solut.shortestHaveTwice(str1)<<endl;
    cout<<solut.shortestHaveTwice(str2)<<endl;
    cout<<solut.shortestHaveTwice(str3)<<endl;
    cout<<solut.shortestHaveTwice(str4)<<endl;
    cout<<solut.shortestHaveTwice(str5)<<endl;

    return 0;
}

