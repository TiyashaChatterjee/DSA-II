class MyCircularQueue {
    private:
        struct ListNode {
            int value;
            ListNode* next;

        public:
            ListNode (int data1, ListNode* next1){
                value = data1;
                next = next1;
            }
        public:
            ListNode(int data1){
                value = data1;
                next = nullptr;
            }
    };
        int capacity;
        int cnt=0;
        ListNode* front=0;
        ListNode* rear=0;

public:
    MyCircularQueue(int k) {
        capacity=k;
    }
    
    bool enQueue(int value) {
        ListNode* newNode = new ListNode(value, 0);
        if(cnt==capacity){
            cout<<"The Linkedlist is full";
            return false;
        }
        if(front == 0 && rear == 0){
            front=rear=newNode;
            rear->next = newNode;
        }else{
            rear->next=newNode;
            rear=newNode;
            rear->next=front;
        }
        cnt++;
        return true;
    }
    
    bool deQueue() {
        ListNode* temp = front;
        if(front==0 && rear==0){
            printf("It is empty");
            return false;
        }else if(front==rear){
            front=0;
            rear=0;
            delete(temp);
        }else{
            front=front->next;
            rear->next=front;
            temp->next=nullptr;
            delete(temp);
        }
        cnt--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return front->value;
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return rear->value;
    }
    
    bool isEmpty() {
        if(front==0 && rear==0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(capacity==cnt) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */