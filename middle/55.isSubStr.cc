#include "include/tree.h"

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution
{
public:
    vector<int> getNextArr(string &str2)
    {
        vector<int> nextArr(str2.size(),0);

        nextArr[0]=-1;//人为规定
        nextArr[1]=0;//人为规定
        int index=2;
        int cen=0;

        while(index<nextArr.size())
        {
           if(str2[index-1]==str2[cen])
           {
                nextArr[index++]=++cen;
           }else if(cen>0)
           {
               //往回跳到不能再往前跳为止
                cen=nextArr[cen];
           }else{
               //我往回跳到不能再往回跳之后，只能赋值为0
               nextArr[index++]=0;
           }
        }

        return nextArr;
    }

    int kmp(string &str1,string &str2)
    {
        //这样我没法玩
        if(str1.empty()||str2.empty()||str1.size()<str2.size())
            return -1;

        vector<int> nextArr=getNextArr(str2);
        int index1=0;
        int index2=0;

        while(index1<str1.size()&&str2.size())
        {
            if(str1[index1]==str2[index2])
            {
                ++index1;
                ++index2;
            }else if(index2>0)
            {
                //往回跳到不能再往回跳为止
                index2=nextArr[index2];
            }else
            {
                //往回跳到不能再往回跳为止,index1我就++
                ++index1;
            }
        }
        
        return index2==str2.size()?index1-index2:-1;
    }

    void preOrder(TreeNode *head,string &str)
    {
        if(head==nullptr)
        {
            str+="#";
            return;
        }

        str+=std::to_string(head->value);
        preOrder(head->left,str);
        preOrder(head->right,str);

        //剩下的交给KMP算法了
        
    }

    bool isSubStr(TreeNode *T1,TreeNode *T2)
    {
        string str1;
        string str2;
        preOrder(T1,str1);
        preOrder(T2,str2);

        return kmp(str1,str2);
    }
};

int main()
{
    TreeNode *T1=createTree();
    TreeNode *T2=createTree1();

    printTree(T1);
    printTree(T2);
    cout<<endl;
    Solution solut;
    cout<<solut.isSubStr(T1,T2)<<endl;

    return 0;
}

