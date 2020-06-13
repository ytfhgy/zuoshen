#include "include/tree.h"

#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::queue;

class Solution
{
public:
    void inOrder(TreeNode *head,queue<TreeNode*> &myQueue)
    {
        if(head)
        {
            inOrder(head->left,myQueue);
            myQueue.push(head);
            inOrder(head->right,myQueue);
        }
    }

    TreeNode *BSTtoDoubleLinkedList(TreeNode *head)
    {
        queue<TreeNode*> myQueue;
        inOrder(head,myQueue);//先玩一次中序遍历并且进队列

        head=myQueue.front();
        myQueue.pop();
        
        TreeNode *pPre=head;
        pPre->left=nullptr;
        TreeNode *pCur=nullptr;
    
        while(!myQueue.empty())
        {
            pCur=myQueue.front();
            myQueue.pop();

            pPre->right=pCur;
            pCur->left=pPre;
            pPre=pCur;
        }

        return head;
    }

    struct Info
    {
        Info(TreeNode *a,TreeNode *b)
        :start(a)
        ,end(b)
        {}
        
        TreeNode *start;
        TreeNode *end;
    };

    Info process(TreeNode *head)
    {
        if(head==nullptr)
            return Info(nullptr,nullptr);

        //分别向左右子树要信息
        Info leftInfo=process(head->left);
        Info rightInfo=process(head->right);

        if(leftInfo.end)
            leftInfo.end->right=head;

        head->left=leftInfo.end;
        head->right=rightInfo.start;

        if(rightInfo.start)
            rightInfo.start->left=head;
        
        //返回的是左子树的头，右子树的尾
        return Info(leftInfo.start?leftInfo.start:head,rightInfo.end?rightInfo.end:head);
    }

    TreeNode *BSTtoDoubleLinkedListdp(TreeNode *head)
    {
        if(head==nullptr)
            return nullptr;

        return process(head).start;
    }

    void printBSTtoDoubleLinkedList(TreeNode *head)
    {
        cout<<"print double linked list:"<<endl;

        TreeNode *end=nullptr;

        while(head)//先从头到尾
        {
            cout<<head->value<<" ";
            end=head;
            head=head->right;
        }
        
        cout<<" | ";
        while(end)//再从尾到头
        {
            cout<<end->value<<" ";
            end=end->left;
        }

        cout<<endl;
    }
};

int main()
{
    Solution solut;

    TreeNode *head=createTree();
    TreeNode *headdp=createTree();
    printTree(head);

    head=solut.BSTtoDoubleLinkedList(head);
    solut.printBSTtoDoubleLinkedList(head);

    headdp=solut.BSTtoDoubleLinkedListdp(headdp);
    solut.printBSTtoDoubleLinkedList(headdp);

    //destory(head);

    return 0;
}

