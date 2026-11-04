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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=NULL && fast->next!=NULL){
            fast= fast->next->next;
            slow=slow->next;
        }
        ListNode* first=head;
        ListNode* temp = slow->next;
        ListNode* second=slow->next;
        ListNode* prev = slow->next = nullptr;
        while(temp!=NULL){
            ListNode* Next = temp->next;
            temp->next=prev;
            prev=temp;
            temp=Next;
        }
        second = prev;
        while(second!=NULL){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
    }
};
