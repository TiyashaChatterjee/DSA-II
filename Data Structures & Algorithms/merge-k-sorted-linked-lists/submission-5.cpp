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
    ListNode* merge(ListNode* head, ListNode* lst){
        ListNode* temp1 = head;
        ListNode* temp2 = lst;
        ListNode* dummy = new ListNode (-1);
        ListNode* temp = dummy;
        if(temp1==NULL){
            temp->next=temp2;
            // temp2=temp2->next;

        }
        if(temp2==NULL){
            temp->next=temp1;
            // temp1=temp1->next;
        }
        while(temp1!=NULL && temp2 != NULL){
            if(temp1->val > temp2->val){
                temp->next=temp2;
                temp2=temp2->next;
            }else{
                temp->next=temp1;
                temp1=temp1->next;
            }
            temp=temp->next;
        }
        if(temp1!=NULL){
            temp->next=temp1;
        }
        if(temp2!=NULL){
            temp->next=temp2;
        }
        ListNode* res = dummy->next;
        delete(dummy);
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        while(lists.size()>1){
            vector<ListNode*>mergedList;
            for(int i=0;i<lists.size();i=i+2){
                ListNode* l1 = lists[i];
                ListNode* l2 = i+1 < lists.size() ? lists[i+1]:nullptr;
                ListNode* head = merge(l1, l2);
                mergedList.push_back(head);
            }
            lists=mergedList;
        }
        return lists[0];
        
    }
};
