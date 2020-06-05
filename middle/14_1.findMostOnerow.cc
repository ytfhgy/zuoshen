#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::list;

class Solution
{
public:
    list<int> findMostOneRow(vector<vector<int>> &matrix)
    {
        //从右上角开始
        int row=0;
        int colum=matrix[0].size()-1;

        list<int> resList; 
        int count=0;
        int maxNumber=0;

        while(row<matrix.size())
        {
            if(colum>0&&matrix[row][colum]==1)
            {
                count++;
                colum--;
                if(colum==-1)
                    colum=0;
            }else if(colum==0&&matrix[row][colum]==1) 
            {
                resList.push_back(row);
                maxNumber=matrix[0].size();
                row++;
            }else if(matrix[row][colum]==0)
            {
                if(count)
                {
                    if(maxNumber<count)
                    {
                        while(!resList.empty())
                        {
                            resList.pop_back();
                        }
                    }

                    resList.push_back(row);
                    maxNumber=count;
                    count=0;
                }

                row++;
            }
        }

        return resList;
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
    int arr[5][10]={{0,0,0,0,0,0,0,1,1,1},
                {0,0,0,1,1,1,1,1,1,1},
                {0,0,0,0,01,1,1,1,1,1},
                {1,1,1,1,1,1,1,1,1,1},
                {0,0,0,0,0,0,0,0,0,0}};

    vector<vector<int>> matrix(5,vector<int>(10,0));
    for(int i=0;i<5;++i)
    {
        for(int j=0;j<10;j++)
        {
            matrix[i][j]=arr[i][j];
        }
    }

    solut.printMatrix(matrix);
    cout<<endl;
    list<int> resList=solut.findMostOneRow(matrix);

    while(!resList.empty())
    {
        cout<<resList.front()<<" ";
        resList.pop_front();
    }

    cout<<endl;


    return 0;
}

