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
    ListNode* getLeft(ListNode* head, int left){
        ListNode* temp = head;
        int cnt = 1;
        while(cnt!=left){
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* getRight(ListNode* head, int right){
        ListNode* temp = head;
        int cnt = 1;
        while(cnt!=right){
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* left1 = getLeft(head, left);
        ListNode* right1 = getRight(head, right);

        ListNode* afterRight;
        ListNode* beforeLeft;
        
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* temp = dummy;

        for (int i = 0; i < left-1; i++) {
            temp=temp->next;
        }
        
        beforeLeft = temp;
        afterRight = right1->next;

        temp = left1;
        ListNode* prev = nullptr;
        for(int i=0;i<(right-left+1);i++){
            ListNode* newNode = temp->next;
            temp->next=prev;
            prev=temp;
            temp=newNode;
        }
        beforeLeft->next=prev;
        left1->next=afterRight;
        
        return dummy->next;
    }
};