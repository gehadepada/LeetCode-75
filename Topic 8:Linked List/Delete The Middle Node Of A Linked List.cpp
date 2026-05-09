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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*temp=head;
        if(head->next==nullptr)
        {
            return nullptr;
        }
        int count =0;
        int delIndex=0 , currentIndex = 0;
        while(temp!=nullptr)
        {
            count++;
            temp=temp->next;
        }
        delIndex=count/2;
        temp=head;
        while(temp!=nullptr)
        {
            if(currentIndex == delIndex-1)
            {
                temp->next=temp->next->next;
                break;
            }
            currentIndex++;
            temp=temp->next;
        }
        return head;
        
    }
};