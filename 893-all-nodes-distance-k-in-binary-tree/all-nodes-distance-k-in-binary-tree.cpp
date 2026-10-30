/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&mp)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *current=q.front();
            q.pop();
            if(current->left)
            {
                mp[current->left]=current;
                q.push(current->left);
            }
            if(current->right)
            {
                mp[current->right]=current;
                q.push(current->right);
            }

        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        markparent(root,parent);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        visited[target]=true;
        q.push(target);
        int cur_level=0;
        while(!q.empty())
        {
            int size=q.size();
            if(cur_level++==k)
                break;
            for(int i=0;i<size;i++)
            {
                TreeNode* cur=q.front();q.pop();
                if(cur->left && !visited[cur->left])
                {
                    visited[cur->left]=true;
                    q.push(cur->left);
                }
                if(cur->right && !visited[cur->right])
                {
                    visited[cur->right]=true;
                    q.push(cur->right);
                }
                if(parent[cur] && !visited[parent[cur]])
                {
                    visited[parent[cur]]=true;
                    q.push(parent[cur]);
                }
            }
            
        }
        vector<int>res;
        while(!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};