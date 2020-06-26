#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::max;

class Solution
{
public:
    int longestNoRepeatSubstring(string &str)
    {
        if(str.empty())
            return 0;

        map<int,int> myMap;
        for(int i=0;i<256;++i)
        {
            myMap[i]=-1;
        }

        //pre表示必须以str[i-1]字符结尾的情况下，最长无重复字符子串开始位置的前一个位置
        int pre=-1;//初始值为-1
        int len=0;

        for(int i=0;i<str.size();++i)
        {
            pre=max(pre,myMap[str[i]]);
            len=max(len,i-pre);
            myMap[str[i]]=i;
        }

        return len;
    }
    
    //返回最长不重复子串
    string getLongestNoRepeatSubstring(string &str)
    {
        if(str.empty())
            return string("");

        map<int,int> myMqp;
        for(int i=0;i<256;++i)
        {
            myMqp[i]=-1;
        }

        //pre表示必须以str[i-1]字符结尾的情况下，最长无重复字符子串开始位置的前一个位置
        int pre=-1;//初始值设为-1
        int len=0;
        int endindex=0;
        for(int i=0;i<str.size();++i)
        {
            pre=max(pre,myMqp[str[i]]);
            int cur=i-pre;
            if(cur>len)
            {
                len=cur;
                endindex=i;
            }
            myMqp[str[i]]=i;
        }
        
        return str.substr(endindex-len+1,len);
    }
};

int main()
{
    Solution solut;
    string str="aabcb";
    string str1="abcd";

    cout<<solut.longestNoRepeatSubstring(str)<<endl;
    cout<<solut.getLongestNoRepeatSubstring(str)<<endl;
    cout<<solut.longestNoRepeatSubstring(str1)<<endl;
    cout<<solut.getLongestNoRepeatSubstring(str1)<<endl;

    return 0;
}

