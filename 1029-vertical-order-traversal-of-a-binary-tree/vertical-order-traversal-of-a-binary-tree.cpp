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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>todo;
        todo.push({root,{0,0}});
        while(!todo.empty())
        {
            auto c=todo.front();
            todo.pop();
            TreeNode *n=c.first;
            int x=c.second.first,y=c.second.second;
            nodes[x][y].insert(n->val);
            if(n->left)
                todo.push({n->left,{x-1,y+1}});
            if(n->right)
                todo.push({n->right,{x+1,y+1}});
        }
        vector<vector<int>>res;
        for(auto p:nodes)
        {
            vector<int>col;
            for(auto q:p.second)
            {
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
}; 