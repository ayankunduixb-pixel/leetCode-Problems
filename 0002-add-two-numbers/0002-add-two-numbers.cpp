/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // It is the optimal approach
        ListNode* dummyHead= new ListNode (-1);
        ListNode* current = dummyHead;
        int carry =0;
        // iterate over two linked list 
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        while(temp1 != NULL || temp2 != NULL){
            int sum=carry;
            if(temp1){
                sum+=temp1->val;
            }
            if(temp2){
                sum+=temp2->val;
            }
            ListNode* newNode= new ListNode(sum%10);
            carry=sum/10;
            current->next=newNode;
            current=current->next;
            // It means if temp1 or temp2 not null then it will again iterate else stop over any one
            if(temp1) temp1=temp1->next;
            if(temp2) temp2=temp2->next;
        }
        // If carry present it will add a new node at the end (as the list is already in reverse order otherwise we need to make it at the front)
        if(carry){
            ListNode* newNode = new ListNode(carry);
            current->next=newNode;
        }
        return dummyHead->next;
    }
};