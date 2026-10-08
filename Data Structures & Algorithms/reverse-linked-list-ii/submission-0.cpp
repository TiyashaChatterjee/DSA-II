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
ListNode* valueLeft(ListNode* head, int left){
    ListNode* temp = head;
    int cnt = 1;
    while(cnt!=left){
        temp=temp->next;
        cnt++;
    }
    return temp;
}
ListNode* valueRight(ListNode* head, int right){
    ListNode* temp = head;
    int cnt = 1;
    while(cnt!=right){
        temp=temp->next;
        cnt++;
    }
    return temp;
}
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        ListNode* temp=dummy;
        ListNode* left1 = valueLeft(head, left);
        ListNode* right1 = valueLeft(head, right);
        //1. beforeleft
        for(int i=0;i<left-1;i++){
            temp=temp->next;
        }
        ListNode* beforeLeft=temp;
    //afterRight

        ListNode* afterRight = right1->next;
        temp = left1;
//reversal
ListNode* prev = nullptr;
        for(int i=0;i<right-left+1;i++){
            ListNode* nextNode = temp->next;
            temp->next=prev;
            prev = temp;
            temp = nextNode;
        }
        //prev is the newHead
        beforeLeft->next = prev;
        left1->next=afterRight;

        return dummy->next;
    }
};