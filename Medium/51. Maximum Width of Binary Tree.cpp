class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        int width = 1;
        
        while(!q.empty())
        {
            width = max(width, (q.back().second - q.front().second + 1));
            int qsize = q.size();
            for(int i=0; i<qsize; i++)
            {
                pair<TreeNode *, int> node_pair = q.front();
                unsigned int index = node_pair.second;
                q.pop();
                
                if(node_pair.first->left)
                    q.push(make_pair(node_pair.first->left, 2 * index + 1));
                
                if(node_pair.first->right)
                    q.push(make_pair(node_pair.first->right, 2 * index + 2));
            }
        }
        return width;
    }
};