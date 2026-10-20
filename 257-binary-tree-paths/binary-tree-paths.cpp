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
    void helper(TreeNode* root,vector<string>&res,string s)
    {
        if(root==nullptr)
            return;
        if(!root->left && !root->right)
        {
            s+=to_string(root->val);
            res.push_back(s);
            return;
        }
        else
        {
            s+=to_string(root->val)+"->";
            helper(root->left,res,s);
            helper(root->right,res,s);
        }
        return;

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==nullptr)
            return {};
        vector<string>res;
        helper(root,res,"");
        return res;
    }
};