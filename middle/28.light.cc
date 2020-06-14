#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution
{
public:
    int minLight(string &str)
    {
        if(str.empty())
            return 0;
        
        int index=0;//每次走到的位置
        int light=0;//放的灯数

        while(index<str.size())
        {
            if(str[index]=='x')
            {
                ++index;//直接去下一个位置
            }else//这里隐含str[index]为'.'
            {
                ++light;//先放一盏灯再说
                if(index+1==str.size())
                    break;

                if(str[index+1]=='x')
                    index+=2;
                else
                    index+=3;
            }
        }

        return light;
    }
};

int main()
{
    Solution solut;
    string s1="xxx..x...xx.x.";

    cout<<solut.minLight(s1)<<endl;

    return 0;
}

