class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(root==NULL)
            return NULL;
        if(root->val==val)
            return root;
        if(root->val<val)
            return searchBST(root->right,val);
        else
            return searchBST(root->left,val);
    }
};


/*
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
     
        if(root == NULL) {return NULL;}
        
        if(root->val == val) {return root;}
        
        val<root->val ? root = searchBST(root->left, val) : root = searchBST(root->right, val);
        
        return root;
    }
};

*/