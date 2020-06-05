#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    void process(vector<vector<int>> &matrix,int trow,int tcolum,int drow,int dcolum)
    {
        //代表每一框有多少组
        int arrNumber=dcolum-tcolum;
        
        //i代表组号，一组一组地换
        for(int i=0;i<arrNumber;++i)
        {
            int temp=matrix[trow][tcolum+i];
            matrix[trow][tcolum+i]=matrix[drow-i][tcolum];
            matrix[drow-i][tcolum]=matrix[drow][dcolum-i];
            matrix[drow][dcolum-i]=matrix[trow+i][dcolum];
            matrix[trow+i][dcolum]=temp;
        }
    }

    void rotateMatrix(vector<vector<int>> &matrix)
    {
       //左上角坐标和右下角坐标
       //下面的四个变量定义了一个正方形 
       int trow=0;
       int tcolum=0;
       int drow=matrix.size()-1;
       int dcolum=matrix[0].size()-1;

       while(trow<drow)//因为是正方形，所以判断一个就行了
       {
           process(matrix,trow++,tcolum++,drow--,dcolum--);
       }

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
    int arr[5][5]={{1,2,3,4,5},
                    {6,7,8,9,10},
                    {11,12,13,14,15},
                    {16,17,18,19,20},
                    {21,22,23,24,25}};
    vector<vector<int>> matrix(5,vector<int>(5,0));
    for(int i=0;i<5;++i)
    {
        for(int j=0;j<5;++j)
        {
            matrix[i][j]=arr[i][j];
        }
    }

    solut.printMatrix(matrix);
    cout<<endl;
    solut.rotateMatrix(matrix);
    solut.printMatrix(matrix);

    return 0;
}

