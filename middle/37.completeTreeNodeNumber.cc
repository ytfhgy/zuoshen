#include "include/tree.h"
#include <iostream>

using std::cout;
using std::endl;

class Solution
{
public:
    //如果node在第level层
    //求以node为头的子树，最大深度是多少
    //node为头的子树，一定是完全二树
    int mostLeftLevel(TreeNode *head,int level)
    {
        while(head)
        {
            ++level;
            head=head->left;
        }

        return level-1;
    }

    //head在第level层，h是总深度(上是不变的A)
    //以head为头的完全二叉树，节点个数是多少
    int bs(TreeNode *head,int level,int h)
    {
        if(level==h)
            return 1;//说明来到了根结点

        if(mostLeftLevel(head->right,level+1)==h)
           return(1<<(h-level))+bs(head->right,level+1,h); 
        else
            return (1<<(h-level-1))+bs(head->left,level+1,h);
    }

    //请保证head为头的树，是完全二叉树
    int completeTreeNodeNumber(TreeNode *head)
    {
        if(head==nullptr)
            return 0;

        return bs(head,1,mostLeftLevel(head,1));
    }

};

int main()
{
    Solution solut;
    TreeNode *head;

    head=createTree();
    printTree(head);

    cout<<solut.completeTreeNodeNumber(head)<<endl;

    return 0;
}
