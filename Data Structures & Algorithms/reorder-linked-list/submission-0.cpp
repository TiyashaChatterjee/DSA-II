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
            slow = slow->next;
            fast=fast->next->next;
        }
        //reverse
        ListNode* first = head;
        ListNode* second = slow->next;
        ListNode* temp = slow->next;
        //break it
        ListNode* prev = slow->next = nullptr;
        while(temp!=NULL){
            ListNode* next = temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        second = prev;
        while(second!=nullptr){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next=second;
            second->next=tmp1;
            first=tmp1;
            second=tmp2;
        }
    }
};
