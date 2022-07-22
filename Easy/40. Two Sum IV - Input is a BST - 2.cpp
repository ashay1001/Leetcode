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
class BSTIterator{
public:
    stack<TreeNode*> st;
    bool reverse = true;
    
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext()
    {
        return !st.empty();
    }
    int next()
    {
        TreeNode *temp = st.top(); st.pop();
        if(reverse == false)
            pushAll(temp->right);
        else
            pushAll(temp->left);
        return temp->val;
    }
private:
    void pushAll(TreeNode *root)
    {
        while(root)
        {
            st.push(root);
            if(reverse == false)
                root = root->left;
            else
                root = root->right;
        }
    }
};

class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) {
        BSTIterator left(root, false);
        BSTIterator right(root, true);
        
        int i = left.next();
        int j = right.next();
        
        while(i < j)
        {
            if(i+j == k) return true;
            if(i+j < k)
                i = left.next();
            else
                j = right.next();
        }
        return false;
    }
};