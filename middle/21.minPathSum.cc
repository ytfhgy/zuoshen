#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::min;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &matrix)
    {
        if(matrix.size()==0||matrix[0].size()==0)
            return 0;

        int N=matrix.size();//行
        int M=matrix[0].size();//列

        vector<vector<int>> dp(N,vector<int>(M,0));
        
        //进行初始化
        dp[0][0]=matrix[0][0];
        for(int colum=1;colum<M;++colum)
        {
            dp[0][colum]=dp[0][colum-1]+matrix[0][colum];
        }

        for(int row=1;row<N;++row)
        {
            dp[row][0]=dp[row-1][0]+matrix[row][0];
            for(int colum=1;colum<M;++colum)
            {
                //依赖它的的左方和上方，谁小加谁的
                dp[row][colum]=min(dp[row-1][colum],dp[row][colum-1])+matrix[row][colum];
            }
        }

        return dp[N-1][M-1];
    }

    //可以进行二维空间的压缩,降低空间复杂度
    int minPathSum1(vector<vector<int>> &matrix)
    {
        if(matrix.size()==0||matrix[0].size()==0)
            return 0;

        int N=matrix.size();//行
        int M=matrix[0].size();//列
        
        //用一维数组即可实现
        vector<int> dp(M,0);

        //进行初始化
        dp[0]=matrix[0][0];
        for(int i=1;i<M;++i)
        {
            dp[i]=dp[i-1]+matrix[0][i];
        }

        for(int row=1;row<N;++row)
        {
            dp[0]=dp[0]+matrix[row][0];
            for(int colum=1;colum<M;++colum)
            {
                //跟它的左方和上方有关，谁小加谁
                dp[colum]=min(dp[colum-1],dp[colum])+matrix[row][colum];
            }
        }

        return dp[M-1];
        
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

    int arr[4][5]={{3,2,4,6,0},
                    {2,1,9,7,5},
                    {7,12,4,3,7},
                    {4,3,1,9,7}};
    vector<vector<int>> matrix(4,vector<int>(5,0));
    for(int i=0;i<matrix.size();++i)
    {
        for(int j=0;j<matrix[0].size();++j)
        {
            matrix[i][j]=arr[i][j];
        }
    }

    solut.printMatrix(matrix);
    cout<<endl;

    cout<<"minPathSum:"<<solut.minPathSum(matrix)<<endl;
    cout<<"minPathSum:"<<solut.minPathSum1(matrix)<<endl;

    return 0;
}

