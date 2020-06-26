#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::map;

class Solution
{
public:
    string removeDouplicateLetterLessLexi(string &str)
    {
        if(str.empty())
            return string("");

        //先统计str中每个字符的字频
        //如果charCount[i]>-1，则代表ascii码值为i的字符的出现次数
        //如果charCount[i]==-1，则代表asscii码值为i的字符不再考滤
        map<int,int> charCount;
        for(int i=0;i<str.size();++i)
        {
            charCount[str[i]-'a']++;
        }

        string res(26,'a');
        int index=0;
        int left=0;
        int right=0;

        while(right<str.size())
        {
            //如果当前字符是不再考滤的，直接跳过去
            //如果当前字符的出现次数减1之后，后面还能出现，也直接跳过
            if(charCount[str[right]-'a']==-1||--charCount[str[right]-'a']>0)
            {
                ++right;
            }else//当前字符需要考滤并且之后不会再出现了
            {
                //在str[left...right]上所有需要考滤的字符中，找到ascii码最小字符的位置
                int pick=-1;
                for(int i=left;i<=right;++i)
                {
                    if(charCount[str[i]-'a']!=-1&&(pick==-1||str[i]<str[pick]))
                    {
                        pick=i;//我找到了最小的那个字符
                    }
                }

                //把ascii码最小的字符放到挑选结果中
                res[index++]=str[pick];

                //在上一个的for循环中，str[left...right]范围上每种字符的出现次数都减少了
                //则需要把str[pick+1...right]上每种字符的出现次数再加回来
                for(int i=pick+1;i<=right;++i)
                {
                    if(charCount[str[i]-'a']!=-1)//只增加以后需要考滤字符的次数
                    {
                        ++charCount[str[i]-'a'];
                    }
                }

                //选出最小的字符，以后都不会再考了
                charCount[str[pick]-'a']=-1;
                //继续在str[pick+1...]上重复这个过程
                left=pick+1;
                right=left;
            }
        }

        return res.substr(0,index);
    }
};

int main()
{
    Solution solut;
    string str="baacbaccac";
    string str1="acbc";

    cout<<solut.removeDouplicateLetterLessLexi(str)<<endl;
    cout<<solut.removeDouplicateLetterLessLexi(str1)<<endl;

    return 0;
}

