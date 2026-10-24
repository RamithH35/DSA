/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode *root=builder(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
    TreeNode* builder(vector<int>& postorder,int poststart,int postend ,vector<int>& inorder,int instart,int inend,map<int,int>&mp)
    {
        if(poststart>postend || instart>inend)
            return nullptr;
        TreeNode *root=new TreeNode(postorder[postend]);
        int inpos=mp[root->val];
        int numleft=inpos-instart;
        root->right=builder(postorder,poststart+numleft,postend-1,inorder,inpos+1,inend,mp);
        root->left=builder(postorder,poststart,poststart+numleft-1,inorder,instart,inpos-1,mp);
        return root;
    }
};

