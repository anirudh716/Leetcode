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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)    
            return true;
        int lh = getHeight(root -> left);
        int rh = getHeight(root -> right);

        return abs(lh - rh) <= 1 && isBalanced(root -> left) && isBalanced(root -> right);
    }

    int getHeight(TreeNode* node){
        if(node == NULL)    
            return 0;

        int lh = getHeight(node -> left);
        int rh = getHeight(node -> right);

        return max(lh, rh) + 1;
    }
};