/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //1. create map
        map<Node*, Node*>mpp;
        Node* temp = head;
        //1. Create a dummy node and Insert in map 
        while(temp!=NULL){
            Node* newNode = new Node (temp->val);
            mpp[temp]=newNode;
            temp=temp->next;
        }
        //creating random pointer linkings
        temp=head;
        while(temp!=NULL){
            Node* newNode = mpp[temp];
            newNode->next = mpp[temp->next];
            newNode->random = mpp[temp->random];

            temp=temp->next;
        }
        return mpp[head];
    }
};
