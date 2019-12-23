#include "mslist.h"

slist::slist()
{
    m_head = NULL;
    m_nListDataCount = 0;
}

slist::~slist()
{
    Node *p, *pnext;
    for (p = m_head; p != NULL; p = pnext)
    {
        pnext = p->next;
        free(p);
    }
    m_nListDataCount = 0;
}

void slist::push_front(int &k, int &v)
{
    Node *pNode = (Node *)malloc(sizeof(Node));
    pNode->key = k;
    pNode->value = v;
    pNode->next = m_head;
    m_head = pNode;
    m_nListDataCount++;
}

bool slist::find(int &k)
{
    for (Node *p = m_head; p != NULL; p = p->next)
        if (p->key == k)
            return true;

    return false;
}

int slist::getByKey(int &k)
{
    for (Node *p = m_head; p != NULL; p = p->next)
    {
        if (p->key == k)
            return p->value;
    }
    return -1;
}

int slist::size()
{
    return m_nListDataCount;
}

//删除链表中第一个值为k的结点
bool slist::remove(int &k)
{
    Node *pNode, *pPreNode;
    pPreNode = pNode = m_head;
    while (pNode != NULL)
    {
        if (pNode->key == k)
        {
            if (pPreNode != pNode)
                pPreNode->next = pNode->next;
            else
                m_head = NULL;
            free(pNode);
            m_nListDataCount--;
            return true;
        }
        pPreNode = pNode;
        pNode = pNode->next;
    }
    return false;
}

void slist::clear()
{
    Node *cur = m_head;
    while (cur != NULL)
    {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    m_head = NULL;
}