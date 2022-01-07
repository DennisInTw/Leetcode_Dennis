class MyLinkedList {
public:
    static int nodeCount;
    static MyLinkedList* dummyHead;
    
    int val;
    MyLinkedList* next;
    /** Initialize your data structure here. */
    MyLinkedList() {
        this->val = 0;
        this->next = NULL;
        
        if (nodeCount == -1) {
            dummyHead = this;
            nodeCount = 0;
        }
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        MyLinkedList* curPtr = dummyHead->next;
        int i = 0;
        
        if (index < 0 || index >= nodeCount)
            return -1;
        
        while (i<index) {
            curPtr = curPtr->next;
            i++;
        }
        
        return curPtr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyLinkedList* newNode = new MyLinkedList();
        newNode->val = val;
        newNode->next = dummyHead->next;
        
        dummyHead->next = newNode;
        nodeCount++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyLinkedList* newNode = new MyLinkedList();
        newNode->val = val;
        newNode->next = NULL;
        
        if (dummyHead->next != NULL) {
            MyLinkedList* curPtr = dummyHead->next;
            while (curPtr->next != NULL) {
                curPtr = curPtr->next;
            }
            
            curPtr->next = newNode;
            
        } else {
            dummyHead->next = newNode;
        }
        
        nodeCount++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
        } else if (index == nodeCount) {
            addAtTail(val);
        } else if (0 < index && index < nodeCount) {
            MyLinkedList* newNode = new MyLinkedList();
            newNode->val = val;
            MyLinkedList* curPtr = dummyHead->next;
            MyLinkedList* tmpPtr = NULL;
            
            int i = 0;
            
            while (i < index-1) {
                curPtr = curPtr->next;
                i++;
            }
            
            tmpPtr = curPtr->next;
            curPtr->next = newNode;
            newNode->next = tmpPtr;
            
            nodeCount++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (0 <= index && index < nodeCount) {
            int i = 0;
            MyLinkedList* curPtr = dummyHead;
            MyLinkedList* tmpPtr = NULL;
            
            while (i < index) {
                curPtr = curPtr->next;
                i++;
            }
            
            tmpPtr = curPtr->next;
            curPtr->next = tmpPtr->next;
            
            delete tmpPtr;
            
            nodeCount--;
        }
        
    }
};

int MyLinkedList::nodeCount = -1;
MyLinkedList* MyLinkedList::dummyHead = NULL;

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
