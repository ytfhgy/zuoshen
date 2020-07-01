#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;
using std::min;

class Solution
{
public:
    struct Node
    {
        Node(int s,int i1,int i2)
            :_sum(s)
             ,_index1(i1)
             ,_index2(i2)
        {}

        int _sum;
        int _index1;
        int _index2;
    };

    struct comp
    {
        bool operator()(const Node &node1,const Node &node2) const
        {
            return node1._sum<node2._sum;
        };

    };

    vector<int> topKSumCrossTwoArrays(vector<int> &vec1,vector<int> &vec2,int topK)
    {
        if(vec1.empty()||vec2.empty()||topK<1)
            return vector<int>();

        //处理传进来的topK会越界问题
        int len=vec1.size()*vec2.size();
        topK=min(topK,len);

        vector<int> res(topK,0);
        int indexK=0;
        priority_queue<Node,vector<Node>,comp> myQueue;//大根堆

        int index1=vec1.size()-1;
        int index2=vec2.size()-1;

        myQueue.push(Node(vec1[index1]+vec2[index2],index1,index2));
        vector<vector<int>> isEnter(vec1.size(),vector<int>(vec2.size(),0));//用来标记我到底进没进过堆
        isEnter[index1][index2]=1;

        while(indexK<topK)
        {
            //弹出一个我就收集一个
            Node node=myQueue.top();//弹出一个
            myQueue.pop();
            res[indexK++]=node._sum;//我就收集一个

            if(index1>0&&!isEnter[index1-1][index2])
            {
                myQueue.push(Node(vec1[index1-1]+vec2[index2],index1-1,index2));
                isEnter[index1-1][index2]=1;
            }
            if(index2>0&&!isEnter[index1][index2-1])
            {
                myQueue.push(Node(vec1[index1]+vec2[index2-1],index1,index2-1));
                isEnter[index1][index2-1]=1;
            }
        }

        return res;
    }
};

int main()
{
    int arr1[6]={3,6,9,12,20,35};
    int arr2[5]={3,5,7,9,27};
    vector<int> vec1(arr1,arr1+6);
    vector<int> vec2(arr2,arr2+5);
    Solution solut;

    vector<int> res=solut.topKSumCrossTwoArrays(vec1,vec2,3);
    for(auto it:res)
    {
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}

