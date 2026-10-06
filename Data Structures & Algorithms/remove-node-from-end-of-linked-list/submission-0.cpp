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
    // You have to write this yourself
int getLength(ListNode* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(getLength(head)<n){
            return nullptr;
        }
        if(head==NULL){
            return nullptr;
        }
        int real = getLength(head)-n+1;
        ListNode* temp=head;
        if(getLength(head)==n){
            ListNode* next = head->next;
            head=next;
            return head;
        }
        int cnt=1;
        ListNode* prev=NULL;
        while(cnt!=real){
            ListNode* next = temp->next;
            prev=temp;
            temp=next;
            cnt++;
        }
        prev->next=temp->next;
        temp->next=NULL;
        delete(temp);
        return head;
    }
};
