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
//brute force
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>node;
        for (ListNode* lst:lists) {
            while(lst){
                node.push_back(lst->val);
                lst=lst->next;
            }
        }
        sort(node.begin(), node.end());

        ListNode* newNode = new ListNode(0);
        ListNode* curr=newNode;
        for(int i:node){
            curr->next = new ListNode(i);
            curr=curr->next;
        }
        return newNode->next;
    }
};
