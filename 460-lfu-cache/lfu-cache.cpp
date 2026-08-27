class LFUCache {
public:
    struct Node{
        int key;
        int val;
        int freq;
        Node *next;
        Node *prev;
        Node(int k,int v)
        {
            key=k;
            val=v;
            freq=1;
            next=nullptr;
            prev=nullptr;
        }
    };
    struct List{
        int size;
        Node *head;
        Node *tail;
        List()
        {
            head = new Node(0,0);
            tail = new Node(0,0);
            head->next=tail;
            tail->prev=head;
            size=0;
        }
        void addfront(Node *node)
        {
            Node *temp=head->next;
            node->next=temp;
            temp->prev=node;
            head->next=node;
            node->prev=head;
            size++;
        }
        void delend(Node *node)
        {
            Node *prevnode=node->prev;
            Node *nextnode=node->next;
            prevnode->next=nextnode;
            nextnode->prev=prevnode;
            size--;
        }
    };
    unordered_map<int,List*>freqList;
    unordered_map<int,Node*>keynode;
    int currsize;
    int capacity;
    int minfreq;
    LFUCache(int capacity) {
        this->capacity=capacity;
        currsize=0;
        minfreq=0;
    }
    void updatefreq(Node *node)
    {
        int oldfreq=node->freq;
        freqList[oldfreq]->delend(node);
        if(oldfreq==minfreq && freqList[oldfreq]->size==0)
            minfreq++;
        node->freq++;
        if(freqList.find(node->freq)==freqList.end())
        {
            freqList[node->freq] = new List();
        }
        freqList[node->freq]->addfront(node);
    }
    
    int get(int key) {
        if(keynode.find(key)==keynode.end())
            return -1;
        Node *node=keynode[key];
        int v=node->val;
        updatefreq(node);
        return v;
    }
    
    void put(int key, int value) {
        if(capacity==0)
            return;
        if(keynode.find(key)!=keynode.end())
        {
            Node *node=keynode[key];
            node->val=value;
            updatefreq(node);
            return;
        }
        if(currsize==capacity)
        {
            List *list=freqList[minfreq];
            Node *lrunode=list->tail->prev;
            keynode.erase(lrunode->key);
            list->delend(lrunode);
            delete lrunode;
            currsize--;
        }
        Node *node=new Node(key,value);
        minfreq=1;
        if(freqList.find(1)==freqList.end())
            freqList[1]=new List();
        freqList[1]->addfront(node);
        keynode[key]=node;
        currsize++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */