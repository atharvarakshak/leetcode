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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        head = head->next;
        vector<int> c,ans;
        int pos=0;
        while(curr!=nullptr && curr->next != nullptr){
            if(prev != nullptr ){
                if((curr->val > prev->val && curr->val >curr->next->val )||(curr->val < prev->val && curr->val < curr->next->val)){
                    c.push_back(pos);
                }
            }
            prev=curr;
            curr = curr->next;
            pos++;
            
        }
        if (c.size() < 2) {
            return {-1, -1};
        }
               int minDistance = INT_MAX;
        int maxDistance = c.back() - c.front();
        
        for (int i = 1; i < c.size(); i++) {
            minDistance = min(minDistance, c[i] - c[i - 1]);
        }
        
        return {minDistance, maxDistance};
     

    }
};