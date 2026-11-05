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
    TreeNode* helper(TreeNode* root,int &k,int &n)
    {
        if(root==nullptr)
            return nullptr;
        TreeNode* left=helper(root->left,k,n);
        if(left)
            return left;
        ++n;
        if(n==k)
            return root;
        return helper(root->right,k,n);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        TreeNode *ans= helper(root,k,cnt);
        if(!ans)
            return 0;
        return ans->val;
    }
};