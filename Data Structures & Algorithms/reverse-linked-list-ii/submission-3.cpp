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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>array;
        ListNode* temp = head;
        int cnt = 1;
        while(cnt<left){
            cnt++;
            temp=temp->next;
        }
        for(int i = 0 ;i<right-left+1;i++){
            array.push_back(temp->val);
            temp=temp->next;
        }
        reverse(array.begin(), array.end());

        temp=head;
        cnt = 1;
        while(cnt<left){
            temp = temp->next;
            cnt++;
        }
        for(int i=0;i<array.size();i++){
            temp->val=array[i];
            temp=temp->next;
        }
        return head;
    }
};