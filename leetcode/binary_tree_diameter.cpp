/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
    	pair<int,int> root_properties = getDiameter(root);

    	return root_properties.second;
    }

    pair<int,int> getDiameter(TreeNode* root){
    	if(!root){return make_pair(0,0);}

    	int left_subtree_size = 0;
    	int righ_subtree_size = 0;
    	int max_subtree_diameter = 0;

    	if(root->left){
    		pair<int,int> left = getDiameter(root->left);
    		left_subtree_size = left.first + 1;
    		max_subtree_diameter = left.second;
    	}

    	if(root->right){
    		pair<int,int> right = getDiameter(root->right);
    		right_subtree_size = right.first + 1;
    		max_subtree_diameter = max(max_subtree_diameter, right.second);
    	}

    	int root_size = max(left_subtree_size, right_subtree_size);
    	int diameter = max(diameter, left_subtree_size + right_subtree_size);

    	return make_pair(root_size, diameter);
    }
};