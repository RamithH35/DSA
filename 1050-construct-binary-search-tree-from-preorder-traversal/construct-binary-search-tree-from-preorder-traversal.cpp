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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return makeBST(preorder, INT_MAX, ind);
    }

    TreeNode* makeBST(vector<int> &preorder, int upbound, int &ind){
        if(ind>=preorder.size() || 
            preorder[ind]>upbound) return nullptr;

        TreeNode* root = new TreeNode(preorder[ind++]);

        root->left=  makeBST(preorder, root->val, ind);

        root->right = makeBST(preorder, upbound, ind);

        return root;

    }

};