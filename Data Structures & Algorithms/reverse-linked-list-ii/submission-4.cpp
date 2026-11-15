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
    ListNode* rightval(ListNode* head, int right){
        ListNode* temp = head;
        int cnt = 1;
        while(cnt!=right){
            temp=temp->next;
            cnt++;
        }
        return temp;
    }
    ListNode* leftval(ListNode* head, int left){
        ListNode* temp = head;
        int cnt = 1;
        while(cnt!=left){
            temp=temp->next;
            cnt++;
        }
        return temp;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* right1=rightval(head, right);
        ListNode* left1=rightval(head, left);
        ListNode* dummy = new ListNode (0);
        dummy->next=head;
        ListNode* temp = dummy;
        for (int i = 0; i < left-1; i++) {
            temp=temp->next;
        }
        ListNode* beforeLeft = temp;
        ListNode* afterRight = right1->next;
        temp=left1;
        ListNode* prev = nullptr;
        //reverse
        for (int i = 0; i < right-left+1; i++) {
            ListNode* nextNode = temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextNode;
        }

        beforeLeft->next=prev;
        left1->next=afterRight;
        return dummy->next;
    }
};