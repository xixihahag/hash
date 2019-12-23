#include "hashtable.h"
#include <iostream>
using namespace std;
Hashtable::Hashtable()
{
    primpos = -1;
    datacount = 0;
    curTableSize = 0;
    resize(getNextPrime());

    findnum = 0;
    unfindnum = 0;
}

Hashtable::~Hashtable()
{
    cout << "findnum = " << findnum << " unfindnum = " << unfindnum << endl;
    clear();
}

void Hashtable::clear()
{
    for (auto it : table)
        it.clear();
}

int Hashtable::size()
{
    return datacount;
}

bool Hashtable::remove(int &k)
{
    int key = hashFun(k);
    if (table[key].remove(k))
    {
        datacount--;
        return true;
    }
    return false;
}

int Hashtable::hashFun(int &n)
{
    return (n ^ 0xdeadbeef) % curTableSize;
}

int Hashtable::getNextPrime()
{
    return m_primes[++primpos];
}

void Hashtable::resize(int newTableSize)
{
    if (newTableSize < curTableSize)
        return;

    int oldTableSize = curTableSize;
    curTableSize = newTableSize;

    vector<slist> newtable(newTableSize);
    for (int i = 0; i < oldTableSize; i++)
    {
        Node *node = table[i].m_head;
        while (node)
        {
            int key = hashFun(node->key);
            Node *pNext = node->next;

            node->next = newtable[key].m_head;
            newtable[key].m_head = node;
            node = pNext;
        }
        table[i].m_head = NULL;
    }
    table.swap(newtable);
}

void Hashtable::insert(int &k, int &v)
{
    int key = hashFun(k);
    if (!table[key].find(k))
    {
        datacount++;
        table[key].push_front(k, v);
        if (datacount > curTableSize)
            resize(getNextPrime());
    }
}

bool Hashtable::find(int &k)
{
    int key = hashFun(k);
    if (table[key].find(k))
    {
        findnum++;
        return true;
    }
    unfindnum++;
    return false;
}

int Hashtable::getByKey(int &k)
{
    int key = hashFun(k);
    return table[key].getByKey(k);
}