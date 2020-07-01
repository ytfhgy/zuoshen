#include <iostream>
#include <map>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::max;

struct Point
{
    Point(int x,int y)
    :_x(x)
    ,_y(y)
    {}

    int _x;
    int _y;
};

class Solution
{
public:
    int gcd(int a,int b)
    {
        return b==0?a:gcd(b,a%b);
    }

    int maxPointOneLine(vector<Point> &point)
    {
        if(point.size()<3)
            return point.size();
        int result=0;

        for(int i=0;i<point.size();++i)//直接必须从i号出发，考察i后面的点和i的关系
        {
            int samePosition=1;//它自己原本就算一个点
            int sameX=0;
            int sameY=0;
            int line=0;
            map<int,map<int,int>> myMap;//这是一张二维表

            for(int j=i+1;j<point.size();++j)
            {
                int x=point[j]._x-point[i]._x;
                int y=point[j]._y-point[i]._y;

                if(x==0&&y==0)//在同一位置
                {
                    samePosition++;
                }else if(x==0)//共x轴
                {
                    sameX++;
                }else if(y==0)//共y轴
                {
                    sameY++;
                }else//共斜率
                {
                    int gcdValue=gcd(x,y);
                    x/=gcdValue;
                    y/=gcdValue;
                    
                    if(myMap.find(x)==myMap.end())//x的分子压根就没出现过
                        myMap[x];

                    if(myMap[x].find(y)==myMap[x].end())//x为分子，y为分母的情况压根就没出现过
                        myMap[x][y];

                    myMap[x][y]++;
                    line=max(line,myMap[x][y]);
                }
            }
            
            result=max(max(line,max(sameX,sameX))+samePosition,result);
        }

        return result;
    }
};

int main()
{
    Solution solut;
    vector<Point> point;

    //point.push_back(Point(1,1));
    //point.push_back(Point(2,2));
    //point.push_back(Point(3,3));
    point.push_back(Point(1,1));
    point.push_back(Point(3,2));
    point.push_back(Point(5,3));
    point.push_back(Point(4,1));
    point.push_back(Point(2,3));
    point.push_back(Point(1,4));


    cout<<solut.maxPointOneLine(point)<<endl;

    return 0;
}

