class Solution {
public:
    TreeNode* inorderSuccesor(TreeNode *root)
    {
        TreeNode *temp = root;
        while(temp && temp->left)
        {
            temp = temp->left;
        }
        return temp;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL) {return NULL;}
        
        if(root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else // root->data == key
        {
            if(root->left == NULL) //only one child
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                TreeNode *temp = inorderSuccesor(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }  
        }
         return root;
    }
};