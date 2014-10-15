/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> ret;
        recurse(1,n,ret);
        return ret;
    }

    void recurse(int start, int end, vector<TreeNode *> &ret){
        if(start>end){
            ret.push_back(NULL);
        }

        for(int i=start;i<=end;i++){
            vector<TreeNode *> left;
            recurse(start,i-1,left);
            vector<TreeNode *> right;
            recurse(i+1, end,right);
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ret.push_back(root);
                }
            }
        }
    }
};