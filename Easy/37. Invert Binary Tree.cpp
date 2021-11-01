class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) 
        {
            TreeNode* temp = st.top();
            st.pop();
            if(temp)
            {
                st.push(temp->left);
                st.push(temp->right);
                swap(temp->left, temp->right);
            }
        }
    return root;
    }
};


/* 
*************** Recursive version *****************

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL) {return root;}
        
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
        
    }
};

*/