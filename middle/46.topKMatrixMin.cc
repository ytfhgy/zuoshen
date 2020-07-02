#include <iostream>
#include <vector>
#include <queue>

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
        Node(int value,int index1,int index2)
        :_value(value)
         ,_index1(index1)
         ,_index2(index2)
        {}

        int _value;
        int _index1;
        int _index2;
    };

    struct comp
    {
        bool operator()(const Node &node1,const Node &node2) const
        {
            return node1._value>node2._value;
        }
    };

    vector<int> topkMatrixMin(vector<vector<int>> &matrix,int topK)
    {
        if(matrix.empty()||topK<1)
            return {};

        //这里进行处理是为了防止topK越界了
        int len=matrix.size()*matrix[0].size();
        topK=min(topK,len);

        priority_queue<Node,vector<Node>,comp> myQueue;//小根堆
        vector<vector<int>> isEnter(matrix.size(),vector<int>(matrix[0].size(),0));//用来查看这个位置没有进过堆
        
        vector<int> res(topK,0);
        int index=0;
        myQueue.push(Node(matrix[0][0],0,0));
        isEnter[0][0]=1;
        
        while(index<topK)
        {
            //弹出一个我就收集一个
            Node node=myQueue.top();
            myQueue.pop();
            res[index++]=node._value;

            if(node._index1+1<matrix.size()&&!isEnter[node._index1+1][node._index2])
            {
                myQueue.push(Node(matrix[node._index1+1][node._index2],node._index1+1,node._index2));
                isEnter[node._index1+1][node._index2]=1;//把这个位置标记为我已经进过
            }

            if(node._index2+1<matrix[0].size()&&!isEnter[node._index1][node._index2+1])
            {
                myQueue.push(Node(matrix[node._index1][node._index2+1],node._index1,node._index2+1));
                isEnter[node._index1][node._index2+1]=1;//把这个位置标记为我已经进过
            }
        }

        return res;
    }
};

int main()
{
    Solution solut;
    int arr[3][4]={{1,3,5,7},{2,6,7,9},{9,13,15,19}};
    vector<vector<int>> matrix(3,vector<int>(4,0));

    for(int i=0;i<3;++i)
    {
        for(int j=0;j<4;++j)
        {
            matrix[i][j]=arr[i][j];
        }
    }

    vector<int> res=solut.topkMatrixMin(matrix,5);
    for(auto it:res)
        cout<<it<<" ";
    cout<<endl;

    return 0;
}

