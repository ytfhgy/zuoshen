#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;

class Solution
{
public:

    struct Node
    {
        Node(int val,int r,int c)
        :value(val)
        ,row(r)
        ,colum(c)
        {}

        int value;
        int row;
        int colum;

        bool operator<(const Node &node) const
        {
            return value>node.value;//小根堆
        }
    };

    int trapRainWater(vector<vector<int>> &matrix)
    {
        if(matrix.size()==0||matrix[0].size()==0)
            return 0;
        
        //行和列
        int row=matrix.size();
        int colum=matrix[0].size();
        priority_queue<Node> myQueue;
        
        //与原矩阵等规模，进过的为1，没进过的为0
        vector<vector<int>> isEnter(row,vector<int>(colum,0));
        
        //下面四个循环是为了先把边框加入小根堆
        for(int i=0;i<colum;++i)
        {
            Node node(matrix[0][i],0,i);
            myQueue.push(node);
            isEnter[0][i]=1;
        }

        for(int i=0;i<row;++i)
        {
            Node node(matrix[i][colum-1],i,colum-1);
            myQueue.push(node);
            isEnter[i][colum-1]=1;
        }

        for(int i=0;i<colum;++i)
        {
            Node node(matrix[row-1][i],row-1,i);
            myQueue.push(node);
            isEnter[row-1][i]=1;
        }

        for(int i=0;i<row;++i)
        {
            Node node(matrix[i][0],i,0);
            myQueue.push(node);
            isEnter[i][0]=1;
        }
        
        int maxValue=0;//表示此时的盛水瓶颈
        int res=0;
        
        while(!myQueue.empty())
        {
            Node cur=myQueue.top();
            myQueue.pop();
            
            //如果cur.value>maxValue，则进行更新
            maxValue=maxValue<cur.value?cur.value:maxValue;
            
            //如果存在cur.value上方存在并且没有进过队列
            if(cur.row>0&&isEnter[cur.row-1][cur.colum]==0)
            {
                //如果比maxValue小，则可以盛水
                if(matrix[cur.row-1][cur.colum]<maxValue)
                    res+=maxValue-matrix[cur.row-1][cur.colum];
                
                Node node(matrix[cur.row-1][cur.colum],cur.row-1,cur.colum);
                myQueue.push(node);
                isEnter[cur.row-1][cur.colum]=1;
            }
            
            //如果存在cur.value下方存在并且没有进过队列
            if(cur.row<row-1&&isEnter[cur.row+1][cur.colum]==0)
            {
                //如果比maxValue小，则可以盛水
                if(matrix[cur.row+1][cur.colum]<maxValue)
                    res+=maxValue-matrix[cur.row+1][cur.colum];
                
                Node node(matrix[cur.row+1][cur.colum],cur.row+1,cur.colum);
                myQueue.push(node);
                isEnter[cur.row+1][cur.colum]=1;
            }

            //如果cur.value左方存在并且没有进过队列
            if(cur.colum>0&&isEnter[cur.row][cur.colum]==0)
            {
                //如果比maxValue小，则可以盛水
                if(matrix[cur.row][cur.colum-1]<maxValue)
                    res+=maxValue-matrix[cur.row][cur.colum-1];

                Node node(matrix[cur.row][cur.colum-1],cur.row,cur.colum-1);
                myQueue.push(node);
                isEnter[cur.row][cur.colum-1]=1;
            }

            //如果cur.value右方存在并且没有进过队列
            if(cur.colum<colum-1&&isEnter[cur.row][cur.colum+1]==0)
            {
                //如果比maxValue小，则可以盛水
                if(matrix[cur.row][cur.colum+1]<maxValue)
                    res+=maxValue-matrix[cur.row][cur.colum+1];

                Node node(matrix[cur.row][cur.colum+1],cur.row,cur.colum+1);
                myQueue.push(node);
                isEnter[cur.row][cur.colum+1]=1;
            }
        }

        return res;
    }

    void printMatrix(vector<vector<int>> &matrix)
    {
        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix[0].size();++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Solution solut;
    int arr[6][7]={{7,7,7,7,3,7,7},
                    {7,3,3,8,2,2,7},
                    {6,8,8,3,8,8,7},
                    {7,1,3,8,4,3,4},
                    {7,4,2,8,3,2,7},
                    {7,7,7,8,5,6,7}};

    vector<vector<int>> matrix(6,vector<int>(7,0));
    for(int i=0;i<matrix.size();++i)
    {
        for(int j=0;j<matrix[0].size();++j)
        {
            matrix[i][j]=arr[i][j];
        }
    }

    solut.printMatrix(matrix);
    cout<<solut.trapRainWater(matrix)<<endl;

    return 0;
}

