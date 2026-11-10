class MyCircularQueue {
    private:
        class ListNode{
            public:
            int data;
            ListNode* next;

            public:
            ListNode(int data1, ListNode* next1){
                data=data1;
                next = next1;
            }
            public:
            ListNode(int data1){
                data=data1;
                next=nullptr;
            }
        };
    int cnt = 0;
    int capacity;
    ListNode* front = 0;
    ListNode* rear = 0;
public:
    MyCircularQueue(int k) {
        capacity = k;
    }
    
    bool enQueue(int value) {
        ListNode* newNode = new ListNode (value);
        if(isFull()){
            return false;
        }
        if(front == 0 && rear == 0){
            front=rear=newNode;
            rear->next=newNode;
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
       if(isEmpty()){
         return false;
       }
       if(front==rear){
        front=rear=0;
        temp->next=nullptr;
        delete(temp);
       }else{
        front=front->next;
        temp->next=nullptr;
        delete(temp);
       }
       cnt--;
       return true;
    }
    
    int Front() {
        if(front==0 && rear==0){
            return -1;
        }
        return front->data;
    }
    
    int Rear() {
        if(front==0 && rear==0){
            return -1;
        }
        return rear->data;
    }
    
    bool isEmpty() {
        return (cnt==0);
    }
    
    bool isFull() {
        if(cnt==capacity){
            return true;
        }
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