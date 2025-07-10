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
        if(!head || !head->next)return head;
        ListNode* prev = NULL;
        ListNode* cur;

        while(head){
            cur = head->next;
            head->next = prev;
            prev = head;
            head = cur;

        }

        return prev;


    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* L1 = reverse(l1);
        ListNode* L2 = reverse(l2);
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int c=0;

        while(L1 || L2 || c>0 ){
            int num = c;
          
            if(L1){
                num+=L1->val;
                L1 = L1->next;
            }
            if(L2){
                num+=L2->val;
                L2 = L2->next;
            }

            if(num==0 && c==1){
                cur->next = new ListNode(1);
                c=0;
                
            }
            else if(num>=10){
                cur->next = new ListNode(num-10);
                c=1;
              
            }
            else{
                cur->next = new ListNode(num);
                c=0;
              
            }
            cur = cur->next;
        }

        return reverse(dummy->next);

    }
};