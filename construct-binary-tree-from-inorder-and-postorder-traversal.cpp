// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
 
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return recurse(inorder, postorder, 0,inorder.size()-1, 0, postorder.size()-1);
    }

    TreeNode *recurse(vector<int> &inorder, vector<int> &postorder, int leftInorder, int rightInorder, int leftPost, int rightPost){
        if(leftInorder>rightInorder || leftPost>rightPost){
            return NULL;
        }
        if(rightInorder == leftInorder  || rightPost == leftPost ){
            TreeNode *ret = new TreeNode(postorder[rightPost]);
            return ret;
        }
        TreeNode *ret = new TreeNode(postorder[rightPost]);

        for(int i = leftInorder;i<=rightInorder;i++){
            if(inorder[i] == postorder[rightPost]){
                int lPos = leftPost, rPos = leftPost + (i - leftInorder)-1;
                ret->left = recurse(inorder,postorder,leftInorder,i-1 , lPos, rPos);
                ret->right = recurse(inorder,postorder,i+1, rightInorder ,rPos+1, rightPost-1);
                return ret;
            }
        }
        return ret;
    }
};