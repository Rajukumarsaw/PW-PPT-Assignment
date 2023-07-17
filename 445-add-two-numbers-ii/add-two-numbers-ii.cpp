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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 =reverse(l1);
        l2=reverse(l2);
        int carry=0;
         ListNode* dummy=new ListNode();
         ListNode* curr=dummy;
        while(l1!=NULL && l2!=NULL){
            int val1=l1->val;
            int val2=l2->val;
            int sum= (val1+val2+carry)%10;
            carry=(val1+val2+carry)/10;
            ListNode* node=new ListNode(sum);
            curr->next=node;
            curr=node;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
             int val1=l1->val;
            int sum= (val1+carry)%10;
            carry=(val1+carry)/10;
            ListNode* node=new ListNode(sum);
            curr->next=node;
            curr=node;
            l1=l1->next;
        }
        while(l2!=NULL){
             int val2=l2->val;
            int sum= (val2+carry)%10;
            carry=(val2+carry)/10;
            ListNode* node=new ListNode(sum);
            curr->next=node;
            curr=node;
            l2=l2->next;
        }
        if(carry!=0){
            ListNode* node=new ListNode(carry);
            curr->next=node;
        }

        
        ListNode* head=reverse(dummy->next);
        return head;
    }
};