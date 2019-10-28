#define TRUE 1
#define FALSE 0
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if(p == NULL && q == NULL)
		return TRUE;
	if(p != NULL && q == NULL || p == NULL && q != NULL
		|| p != NULL && q != NULL && p->val != q->val)
		return FALSE;
	return isSameTree(p->left, q->left) 
		&& isSameTree(p->right, q->right);    
}