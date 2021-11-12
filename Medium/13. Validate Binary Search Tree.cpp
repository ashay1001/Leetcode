class Solution {
public:
    vector<int> arr;
    bool isValidBST(TreeNode* root) {
        
        if(root == NULL) {return true;}
        
        traverse(root);
        for(int i=0; i<arr.size()-1; i++)
        {
            if(arr[i] >= arr[i+1]) {return false;}
        }
        return true;
    }
    
    void traverse(TreeNode *root)
    {
        if(root == NULL) {return;}
        
        traverse(root->left);
        arr.push_back(root->val);
        traverse(root->right);
    }
};