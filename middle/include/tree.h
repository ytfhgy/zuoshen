#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

struct TreeNode
{
    TreeNode(int val)
    :value(val)
    ,left(nullptr)
    ,right(nullptr)
    {}

    int value;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *createTree()
{
    TreeNode *head=new TreeNode(6);

    head->left=new TreeNode(9);
    head->right=new TreeNode(-6);

    head->left->left=new TreeNode(7);

    head->left->left->left=new TreeNode(2);
    head->left->left->right=new TreeNode(8);

    return head;
}

string getSpace(int len)
{
    string s;
    for (int i = 0; i < len; ++i)
    {
        s.append(" ");

    }

    return s;
}

void print(TreeNode *root, int height, string to, int len)
{
    if (root == nullptr)
        return;

    print(root->right, height + 1, "v", len);

    string val;
    val.append(to).append(to_string(root->value)).append(to);
    int lenM = val.length();
    int lenL = (len - lenM) / 2;
    int lenR = len - lenM - lenL;

    string result;
    result.append(to_string(lenL)).append(val).append(getSpace(lenR));
    cout << getSpace(height*len) << val << endl;
    print(root->left, height + 1, "^", len);
}

void printTree(TreeNode *root)
{
    cout << "Binary Tree:" << endl;
    print(root, 0, "H", 17);
    cout << endl;
}

void destory(TreeNode *root)
{
    if(root)
    {
        TreeNode *left=root->left;
        TreeNode *right=root->right;
        delete root;
        root=nullptr;
        destory(left);
        destory(right);
    }
}
