class LinkedList {
public: 
    struct Node{
        int value;
        Node* next; 
        Node(int val) : value(val), next(nullptr) {}
    };

private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr; 
        tail = nullptr;
    }

    int get(int index) {
        Node* curr = head;
        int count = 0;
        while (curr != nullptr){
            if (count == index){
                return curr->value;
            }
            count++;
            curr = curr->next; 
        }
        return -1;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode; 
            tail = newNode;
            return;
        }
        newNode->next = head; 
        head = newNode; 
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr){
            head = newNode;
            tail = newNode; 
            return;
        }
        tail->next = newNode;
        tail = newNode; 
    }

    bool remove(int index) {
        if (head == nullptr){
            return false;
        }
        if (index == 0){
            Node* temp = head; 
            head = head->next; 
            if(head == nullptr) tail = nullptr; 
            delete temp;
            return true;
        }
        Node* curr = head; 
        for(int i = 0; i< index -1; i++){
            if (curr->next == nullptr) return false; 
            curr = curr->next; 
        }
        if (curr->next == nullptr) return false; 
        Node* toDelete = curr->next;
        curr->next = curr->next->next;
        if(toDelete == tail) tail = curr; 

        delete toDelete;
        return true; 
    }

    vector<int> getValues() {
        std::vector<int> res;
        Node* curr = head;
        while(curr != nullptr){
            res.push_back(curr->value);
            curr = curr->next;
        }
        return res; 
    }
};
