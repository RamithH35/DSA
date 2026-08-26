class LRUCache {
public:
    class Node
    {
        public:
            int key;
            int val;
            Node *next;
            Node *prev;
            Node(int k,int v)
            {
                key=k;
                val=v;
                next=nullptr;
                prev=nullptr;

            }
    };
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    int cap;
    unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(Node *newnode)
    {
        Node *temp=head->next;
        newnode->next=temp;
        temp->prev=newnode;
        head->next=newnode;
        newnode->prev=head;
    }
    void delNode(Node *newnode)
    {
        newnode->next->prev=newnode->prev;
        newnode->prev->next=newnode->next;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            Node *n=mp[key];
            int val=n->val;
            mp.erase(key);
            delNode(n);
            addNode(n);
            mp[key]=head->next;
            return val;
        }
        return -1;
    }

    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node *n=mp[key];
            n->val=value;
            mp.erase(key);
            delNode(n);
            addNode(n);
            mp[key]=head->next;
            
        }
        else
        {
            if(mp.size()==cap)
            {
                mp.erase(tail->prev->key);
                delNode(tail->prev);
            }
            addNode(new Node(key,value));
            mp[key]=head->next;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */