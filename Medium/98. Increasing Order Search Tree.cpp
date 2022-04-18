class Solution {
public:
    TreeNode* curr;
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans = new TreeNode(0);
        curr = ans;
        inorder(root);
        return ans->right;
    }
    
    void inorder(TreeNode *root)
    {
        if(!root) return;
        
        inorder(root->left);
        root->left = NULL;
        curr->right = root;
        curr = curr->right;
        inorder(root->right);
    }
};

/*

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
    stack<TreeNode*> st;
    TreeNode* increasingBST(TreeNode* root) 
    {
        postOrder(root);
        TreeNode *new_root = new TreeNode(-1);
        TreeNode *temp = new_root;
        while(!st.empty())
        {
            TreeNode* t = st.top(); st.pop();
            t->left = NULL;
            t->right = NULL;
            temp->right = t;
            temp = temp->right;
        }
        return new_root->right;
    }
    
    void postOrder(TreeNode* root)
    {
        if(!root) return;
        postOrder(root->right);
        st.push(root);
        postOrder(root->left);
    }
};

*/