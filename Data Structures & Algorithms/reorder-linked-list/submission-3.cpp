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
        ListNode* fast = head;
        ListNode* slow= head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=slow->next;
        ListNode* prev = slow->next=nullptr;
        while(temp!=nullptr){
            ListNode* nextNode=temp->next;
            temp->next =prev;
            prev=temp;
            temp=nextNode;
        }
        ListNode* temp2 = prev;
        ListNode* temp1 = head;

        while(temp2!=nullptr){
            ListNode* next1=temp1->next;
            ListNode* next2 = temp2->next;
            temp1->next=temp2;
            temp2->next=next1;
            temp1=next1;
            temp2=next2;
        }
    }
};
