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
    bool returnsum(TreeNode *root,int cursum,int target)
    {
        if(!root)
            return false;
        cursum+=root->val;
        if(!root->left && !root->right)
            return cursum==target;
        return returnsum(root->left,cursum,target) || returnsum(root->right,cursum,target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return returnsum(root,0,targetSum);
    }
};