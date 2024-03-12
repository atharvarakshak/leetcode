class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> v;

        // Insert linked list elements into the vector
        ListNode* current = head;
        while (current != nullptr) {
            v.push_back(current->val);
            current = current->next;
        }

        vector<int> ans;
        int n = v.size();
        int l = -1;
        int r = -1;
        for(int i=0;i<v.size();i++)
       {
        int sum=0;
        for(int j=i;j<v.size();j++)
        {
            sum+=v[j];

            if(sum==0)
            {
            v.erase(v.begin()+i,v.begin()+j+1);
            i--;
            break;
            }
        }
       }

        // for(int i = 0 ; i<l ; i++){
        //     ans.push_back(v[i]);
        // }
        // for(int i = r+1 ; i<n ; i++){
        //     ans.push_back(v[i]);
        // }


       ListNode dummy(0);  // Dummy node to simplify code
        ListNode* current2 = &dummy;

        for (int num : v) {
            current2->next = new ListNode(num);
            current2 = current2->next;
        }

         return dummy.next;

    }
};