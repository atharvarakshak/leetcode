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
    ListNode* sortList(ListNode* head) {
        if(!head)return head;
        vector<int> v;
   
    
        while(head){
            v.push_back(head->val);
            head = head->next;
        }

        sort(v.begin(),v.end());

        ListNode* dummy = new ListNode(0);
        ListNode* cur =  dummy;

        for(int i=0;i<v.size();i++){
            cur->next = new ListNode(v[i]);
            cur = cur->next;
        }
        cur=nullptr;

        return dummy->next;
        
    }
};