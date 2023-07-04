#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int sumOfLeftLeaves(TreeNode<int> *root)
{
    //    Write your code here
    int ans = 0;
    if(root->left != NULL){
        TreeNode<int>*child = root->left;
        if(child->left == NULL && child->right == NULL)
        ans += child->val;
    }
    if(root->left!=NULL){
        ans += sumOfLeftLeaves(root->left);
    }
    if(root->right!=NULL){
        ans += sumOfLeftLeaves(root->right);
    }
    return ans;
}