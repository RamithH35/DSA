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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        TreeNode *root= builder(preorder,0,preorder.size()-1,
                                inorder,0,inorder.size()-1,mp);
        return root;
    }
    TreeNode* builder(vector<int>& preorder,int prestart ,int preend,vector<int>& inorder,
    int instart,int inend,map<int,int>&mp)
    {
        if(instart>inend || prestart>preend)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[prestart]);
        int inpre=mp[root->val];
        int numleft=inpre-instart;
        root->left=builder(preorder,prestart+1,prestart+numleft,
                            inorder,instart,inpre-1,mp);
        root->right=builder(preorder,prestart+numleft+1,preend,
                            inorder,inpre+1,inend,mp);
        return root;
    }
};