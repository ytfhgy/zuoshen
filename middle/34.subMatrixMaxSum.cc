#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::max;

class Solution
{
public:
    int subMatrixMaxSum(vector<vector<int>> &matrix)
    {
        if(matrix.empty())
            return 0;

        int cur=0;//当前的子数组累加和
        int maxSum=0;//子矩阵最大的累加和

        for(int i=0;i<matrix.size();++i)//开始的行号i
        {
            vector<int> help(matrix[i].size(),0);

            for(int j=i;j<matrix.size();++j)//结束的行号j,i~j行是我讨论的范围
            {
                for(int k=0;k<matrix[j].size();++k)//变成求最大的子数组累加和
                {
                    help[k]+=matrix[j][k];//得到前j行的和
                    //变成求子数组的最大累加和
                    cur+=help[k];
                    maxSum=max(maxSum,cur);
                    cur=cur<0?0:cur;
                }
            }
        }

        return maxSum;
    }
};

int main()
{
    int arr[3][3]={{-90,48,78},{64,-40,64},{-81,-7,66}};
    vector<vector<int>> matrix(3,vector<int>(3,0));

    for(int i=0;i<matrix.size();++i)
    {
        for(int j=0;j<matrix[0].size();++j)
        {
            matrix[i][j]=arr[i][j];
        }
    }

    Solution solut;

    cout<<solut.subMatrixMaxSum(matrix)<<endl;

    return 0;
}

