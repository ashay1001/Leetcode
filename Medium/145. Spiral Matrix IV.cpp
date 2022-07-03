/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
     
        vector<vector<int>> matrix(m, vector<int>(n));
        int top = 0, bottom = m-1, left = 0, right = n-1, direction = 0;
        
        while(top<=bottom and left<=right)
        {
            if(direction == 0)
            {
                for(int i=left; i<=right; i++)
                {
                    matrix[top][i] = head != NULL ? head->val : -1;
                    head = head != NULL ? head->next : NULL;
                }
                top++;
            }
            else if(direction == 1)
            {
                for(int i=top; i<=bottom; i++)
                {
                    matrix[i][right] = head != NULL ? head->val : -1;
                    head = head != NULL ? head->next : NULL;
                }
                right--;
            }
            else if(direction == 2)
            {
                for(int i=right; i>=left; i--)
                {
                    matrix[bottom][i] = head != NULL ? head->val : -1;
                    head = head != NULL ? head->next : NULL;
                }
                bottom--;
            }
            else if(direction == 3)
            {
                for(int i=bottom; i>=top; i--)
                {
                    matrix[i][left] = head != NULL ? head->val : -1;
                    head = head != NULL ? head->next : NULL;
                }
                left++;
            }
            direction = (direction+1)%4;
        }
        return matrix;
    }
};