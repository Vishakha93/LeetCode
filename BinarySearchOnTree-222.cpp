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
    
    int calculateDepth(TreeNode* root) {
        int d = 0;
        while(root->left != NULL){
            root = root->left;
            ++d;
        }
        return d;
    }
    
    bool exists(int idx, int d, TreeNode *root) {
        if(root == NULL) {
            return false;
        }
        
        int left = 0, right = pow(2, d) - 1;
        for(int i=0; i<d; i++) {
            int mid = (left + right)/2;
            if (idx <= mid) {
                root = root->left;
                right = mid;
            }
            else {
                root = root->right;
                left = mid + 1;
            }
        }
        
        return root != NULL;
    }
    
    
    int countNodes(TreeNode* root) { 
        
        if (root == NULL) {
            return 0;
        }
        int d = calculateDepth(root);
        
        if(d == 0) {
            return 1;
        }
        int upperCount = pow(2, d) - 1;
        int left = 1, right = pow(2, d) - 1, mid;
        while(left <= right) {
            mid = (left + right)/2;
            if(exists(mid, d, root)) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return upperCount + left; 
    }
};
