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
    void outer(TreeNode* root,int &count,int &target)
    {
        if(root==nullptr)
            return;
        inner(root,count,target,0);
        outer(root->left,count,target);
        outer(root->right,count,target);

    }
    void inner(TreeNode *root,int &count,int &target,long long sum)
    {
        if(root==nullptr)
            return;
        sum+=root->val;
        if(sum==target)
            count++;
        inner(root->left,count,target,sum);
        inner(root->right,count,target,sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        outer(root,count,targetSum);
        return count;
    }
};