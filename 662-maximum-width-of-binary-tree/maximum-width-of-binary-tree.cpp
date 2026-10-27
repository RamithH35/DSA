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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
            return 0;
        queue<pair<TreeNode*,long long>>q;
        long long mx=0;
        long long start=-1;
        long long end=-1;
        q.push({root,0});
        while(!q.empty())
        {
            int n=q.size();
            long long offset=q.front().second;
            for(int i=0;i<n;i++)
            {
                auto c=q.front();
                q.pop();
                long long j=c.second-offset;
                if(i==0)
                    start=c.second;
                if(i==n-1)
                    end=c.second;
                TreeNode *r=c.first;
                if(r->left)
                    q.push({r->left,2*j+1});
                if(r->right)
                    q.push({r->right,2*j+2});
                
            }
            mx=max(mx,end-start+1);
        }
        return mx;
    }
};