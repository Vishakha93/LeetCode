/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root == NULL)
            return "#";
        
        string s = to_string(root->val);
        
        string lefts = serialize(root->left);
        string rights = serialize(root->right);
        
        s = s + "," + lefts + "," + rights;
        cout << s << endl;
        return s; 
    }

    TreeNode* deserializeHelper(string data, int *startPos)
    {
        int pos = data.find_first_of(",", *startPos);
        string s = data.substr(*startPos, pos-(*startPos));
        
        //cout << "Startpos = " << *startPos << " " <<  s << endl;
        *startPos = pos+1;
        if(s == "#")
        {
            return NULL;
        }
        
        int num = stoi(s);
        TreeNode* node = new TreeNode(num);
        
        
        node->left = deserializeHelper(data, startPos);
        
        //cout << "Startpos =" << *startPos << endl;
        
        node->right = deserializeHelper(data, startPos);
        
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int startPos = 0;
        TreeNode* res = deserializeHelper(data, &startPos);
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
