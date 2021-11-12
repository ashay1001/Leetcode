class Solution {
public:
    vector<int> v;
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> mp;
        inorderTraversal(root);
        
        for(int i=0; i<v.size(); i++)
        {
            if(mp.find(k-v[i]) != mp.end())
            {
                return true;
            }
            mp[v[i]] = i;
        }
        return false;
    }
    
    void inorderTraversal(TreeNode *root)
    {
        if(root == NULL) {return;}
        inorderTraversal(root->left);
        v.push_back(root->val);
        inorderTraversal(root->right);
    }
};