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
    int findMinDepth(TreeNode* root, int depth)
    {
    	int left_min_depth = 0;
    	int right_min_depth = 0;
    	// found a leaf
    	if(!root->left && !root->right) 
            return depth;
    	else if(root->left && !root->right) 
            return findMinDepth(root->left, depth + 1);
    	else if(!root->left && root->right) 
            return findMinDepth(root->right, depth + 1);
    	else
    	{
    		left_min_depth = findMinDepth(root->left, depth + 1);
    		right_min_depth = findMinDepth(root->right, depth + 1);
    		return left_min_depth < right_min_depth ? left_min_depth : right_min_depth;
    	}
    }
public:
    int minDepth(TreeNode* root) {
        int depth = 0;
        if(!root) return depth;
        return findMinDepth(root, depth + 1);
    }
};

int main(int argc, char const *argv[])
{
	// test case #0
	/* TreeNode * root = new TreeNode(3);
        root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);*/
	
	// test case #1
	TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	Solution newSolution;
	cout << newSolution.minDepth(root) << endl;
	return 0;
}
