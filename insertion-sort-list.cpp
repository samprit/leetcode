class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
    	if(head==NULL || head->next==NULL){
    		return head;
    	}
    	ListNode *temp=head, *inner, *prev, *end;
    	temp = temp->next;
    	end = head;

    	while(temp!=NULL){
    		inner = head;
    		prev = NULL;
    		while(inner!=temp){
    			if(inner->val > temp->val){
    				break;
    			}
    			prev = inner;
    			inner = inner->next;
    		}
    		if(prev == NULL){
    			end->next = temp->next;
    			temp->next = head;
    			head = temp;
    			temp = end->next;
    		}else if(inner == temp){
    			end = temp;
    			temp = temp->next;
    		}else{
    			end->next = temp->next;
    			prev->next = temp;
    			temp->next = inner;
    			temp = end->next;
    		}
    	}
    	return head;
    }
};
