class LRUCache{
    struct Node{
        int key;
        int value;
        Node* next;
        Node* prev;
    };
    unordered_map<int,Node*> hash;
    Node* head=nullptr;
    int currentCapacity;
    int maxCapacity;
public:
    LRUCache(int maxCapacity_) {
        maxCapacity=maxCapacity_;
        currentCapacity=0;
    }

    void setLast(Node* n){
        Node** np = &n;
        *np=n->next;
        n->next=head;
        n->prev=head->prev;
        head->prev=n;
        head=n;
    }

    int get(int key) {
        Node* n;
        try{
            n = hash.at(key);
        }
        catch(out_of_range& oor){
            return -1;
        }
        setLast(n);
        hash[key]=n;
        return n->value;
    }

    void set(int key, int value) {
        if(currentCapacity==maxCapacity){
            hash.erase(head->prev->key);
            head->prev->key=key;
            head->prev->value=value;
            head = head->prev;
            hash[key]=head;
            return;
        }

        Node* n = new Node;
        n->key = key;
        n->value = value;

        if(currentCapacity==0){
            n->prev=n;
            n->next=n;
            head = n;
            hash[key]=head;
            currentCapacity++;
            return;
        }

        n->prev=head->prev;
        n->next=head;
        head->prev=n;
        n->prev->next=n;
        head=n;
        hash[key]=head;
        currentCapacity++;
    }
};
