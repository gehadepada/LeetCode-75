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
    ListNode* reverseList(ListNode* head) {
        ListNode*res = head;
        deque<int>d;
         if(head == nullptr)
         {
            return head;
         }
        while(res)
        {
            d.push_back(res->val);
            res=res->next;

        }
        reverse(d.begin()  , d.end());
        ListNode *r = head;
        ListNode*rr=r;
        while(r)
        {
            r-> val = d.front();
            d.pop_front();
            r=r->next;
        }
        return rr;
        
        
    }
};