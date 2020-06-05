#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    bool findNumberToSortMatrix(vector<vector<int>> &matrix,int number)
    {
        //只有左下角和右上角有单调性
        int row=0;
        int colum=matrix[0].size()-1;

        while(row<matrix.size()&&colum>=0)
        {
            if(matrix[row][colum]>number)
                colum--;
            else if(matrix[row][colum]<number)
                row++;
            else
                return true;
        }

        return false;
    }
    
    void printMatrix(vector<vector<int>> &matric)
    {
        for(int i=0;i<matric.size();++i)
        {
            for(int j=0;j<matric[0].size();++i)
            {
                cout<<matric[i][j]<<" "<<endl;
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
    for(int i=0;i<matrix.size();++i)
    {
        for(int j=0;j<matrix[0].size();++j)
        {
            matrix[i][j]=arr[i][j];
        }
    }

    cout<<solut.findNumberToSortMatrix(matrix,26)<<endl;

    return 0;
}

