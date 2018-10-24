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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        
        if(root==NULL)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> row(size);
            
            for(int i=0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                int idx = leftToRight? i:size-i-1;
                row[idx] = node->val;
                if(node->left)
                {
                    q.push(node->left);
                }
                
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            leftToRight = !leftToRight;
            res.push_back(row);
        }
        
        return res;
    }
};
