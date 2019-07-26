#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int findMinDepth(TreeNode* root, int n)
    {
    	int left_min_depth = 0;
    	int right_min_depth = 0;
    	// found a leaf
    	if(root->left == NULL && root->right == NULL) return n;
    	else if(root->left != NULL) return findMinDepth(root->left, n + 1);
    	else if(root->right != NULL) return findMinDepth(root->right, n + 1);
    	else
    	{
    		left_min_depth = findMinDepth(root->left, n + 1);
    		right_min_depth = findMinDepth(root->right, n + 1);
    		return left_min_depth < right_min_depth ? left_min_depth : right_min_depth;
    	}
    }
public:
    int minDepth(TreeNode* root) {
        int n = 0;
        if(root == NULL) return n;
        return findMinDepth(root, n + 1);
    }
};

int main(int argc, char const *argv[])
{
	TreeNode * root = new TreeNode(3);
        root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	
	Solution newSolution;
	cout << newSolution.minDepth(root) << endl;
	return 0;
}
