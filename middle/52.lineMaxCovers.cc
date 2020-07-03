#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;
using std::max;
using std::min;

class Solution
{
public:
    struct Line
    {
        Line(int start,int end)
        :_start(start)
        ,_end(end)
        {}
       
        int _start;
        int _end;
    };

    struct compStart
    {
        bool operator()(const Line &l1,const Line &l2) const
        {
            return l1._start>l2._start;
        }
    };

    struct compEnd
    {
        bool operator()(const Line &l1,const Line &l2) const
        {
            return l1._end>l2._end;
        }
    };

    int lineMaxCovers(vector<int> &start,vector<int> &end)
    {
        if(start.empty()||end.empty()||start.size()!=end.size())
            return 0;

        priority_queue<Line,vector<Line>,compStart> startQueue;//按照start排序的小根堆
        for(int i=0;i<start.size();++i)
        {
            if(start[i]!=end[i])//只有不等的时候我才进队列
                startQueue.push(Line(start[i],end[i]));
        }
    
        priority_queue<Line,vector<Line>,compEnd> endQueue;//按照end排序的小根堆
        int maxValue=0;

        while(!startQueue.empty())
        {
            Line line=startQueue.top();
            startQueue.pop();

            while(!endQueue.empty()&&endQueue.top()._end<=line._start)
            {
                endQueue.pop();
            }

            endQueue.push(line);
            int curSize=endQueue.size();
            maxValue=max(maxValue,curSize);//每次求最大的
        }

        return maxValue;
    }
    

    //这里的复杂度为O((maxValuue-minValue)*N)，如果数很大时，复杂度是很高的
    int lineMaxCovers1(vector<int> &start,vector<int> &end)
    {
        if(start.empty()||end.empty()||start.size()!=end.size())
            return 0;

        //找到start中的最小值和end中的最小值
        int minValue=0;
        int maxValue=0;

        for(int i=0;i<start.size();++i)
        {
            minValue=min(minValue,start[i]);
            maxValue=max(maxValue,end[i]);
        }
        
        int cover=0;
        //用最小值+0.5后，一直到maxValue试，第第一次有多少个点
        for(double p=minValue+0.5;p<maxValue;++p)
        {
            int curCover=0;
            for(int i=0;i<start.size();++i)
            {
                if(p>start[i]&&p<end[i])//如果符合
                {
                    curCover++;
                }
            }

            cover=max(curCover,cover);
        }

        return cover;
    }
};

int main()
{
    Solution solut;
    int arr1[5]={1,1,1,2,5};
    int arr2[5]={7,4,9,13,10};
    vector<int> start(arr1,arr1+5);
    vector<int> end(arr2,arr2+5);

    cout<<solut.lineMaxCovers(start,end)<<endl;
    cout<<solut.lineMaxCovers1(start,end)<<endl;

    return 0;
}

