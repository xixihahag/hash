
#include <malloc.h>

struct Node
{
    int key;
    int value;
    Node *next;
    Node(int &k, int &v)
    {
        this->key = k;
        this->value = v;
        this->next = NULL;
    }
};

class slist
{
public:
    slist();
    ~slist();
    void push_front(int &, int &);
    bool find(int &);
    int getByKey(int &);

    bool remove(int &);
    void clear();
    int size();

public:
    int m_nListDataCount;
    Node *m_head;
};
