/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int count = 0;
int dfs(struct TreeNode* root, int* sum, int* nodes) {
    if(root == NULL) {
        *sum = 0;
        *nodes = 0;
        return 0;
    }
    int ls, ln, rs, rn;
    dfs(root->left, &ls, &ln);
    dfs(root->right, &rs, &rn);
    *sum = ls + rs + root->val;
    *nodes = ln + rn + 1;
    if(root->val == *sum / *nodes)
        count++;
    return 0;
}
int averageOfSubtree(struct TreeNode* root) {
    int sum, nodes;
    count = 0;
    dfs(root, &sum, &nodes);
    return count;
}