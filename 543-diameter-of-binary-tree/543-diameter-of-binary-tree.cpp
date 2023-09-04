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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findMaxHeight(root, diameter);
        return diameter;
    }
    
    int findMaxHeight(TreeNode* &node, int& diameter){
        if(!node)   return 0;
        
        int lh = findMaxHeight(node -> left, diameter);
        int rh = findMaxHeight(node -> right, diameter);
        diameter = max(diameter, lh + rh);
        
        return 1 + max(lh, rh);
    }
};
