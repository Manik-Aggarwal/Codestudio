#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void solve(BinaryTreeNode < int > * root){
   if(root==NULL) return;
   int childsum=0;
   
   if(root->left) childsum+=root->left->data;
   if(root->right) childsum+=root->right->data;
   
   if (childsum<root -> data) {
       if (root->left) root->left->data =root->data;
       else if(root -> right) root->right->data = root -> data;
   }
   
   solve(root->left);
   solve(root->right);
   
   int sum=0;
   if(root->left) sum+=root->left->data;
   if(root->right) sum+=root->right->data;
    
   if(root->left || root->right) root->data=sum;
}
void changeTree(BinaryTreeNode < int > * root) {
  solve(root);
}  