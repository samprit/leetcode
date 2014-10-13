/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
    	ListNode *temp = head;
    	int i=0;
    	while(temp != NULL){
    		i++;;
    		temp = temp->next;
    	}

    	return recurse(&head,i);
    }

    TreeNode *recurse(ListNode **head, int n){
    	if(n<=0){
    		return NULL;
    	}
    	TreeNode *left = recurse(head,n/2);

    	TreeNode *root = new TreeNode((*head)->val);
    	root->left = left;

    	*head = (*head)->next;

    	root->right = recurse(head, n-n/2-1);

    	return root;
    }
};
