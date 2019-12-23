#include <unordered_map>
#include <map>
#include <iostream>
#include <cstdio>
#include <chrono>
#include <unistd.h>
#include "hashtable.h"
using namespace std;

const int insertn = 100000000; // 1亿

int main()
{
    cout << "--- insert time ---" << endl;
    unordered_map<int, int> umap;
    auto st = chrono::steady_clock::now();
    for (int i = 0; i < insertn; i++)
        umap.insert(make_pair(i, i));
    auto ed = chrono::steady_clock::now();
    auto dur = chrono::duration_cast<chrono::milliseconds>(ed - st).count();
    cout << "umap time: " << dur << " ms." << endl;

    map<int, int> mp;
    st = chrono::steady_clock::now();
    for (int i = 0; i < insertn; i++)
        mp.insert(make_pair(i, i));
    ed = chrono::steady_clock::now();
    dur = chrono::duration_cast<chrono::milliseconds>(ed - st).count();
    cout << "map time: " << dur << " ms." << endl;

    Hashtable hashtable;
    st = chrono::steady_clock::now();
    for (int i = 0; i < insertn; i++)
        hashtable.insert(i, i);
    ed = chrono::steady_clock::now();
    dur = chrono::duration_cast<chrono::milliseconds>(ed - st).count();
    cout << "hashtable time: " << dur << " ms." << endl;

    cout << "--- find time ---" << endl;
    st = chrono::steady_clock::now();
    for (int i = 0; i < insertn; i++)
        umap.find(i);
    ed = chrono::steady_clock::now();
    dur = chrono::duration_cast<chrono::milliseconds>(ed - st).count();
    cout << "umap find time: " << dur << " ms." << endl;

    st = chrono::steady_clock::now();
    for (int i = 0; i < insertn; i++)
        mp.find(i);
    ed = chrono::steady_clock::now();
    dur = chrono::duration_cast<chrono::milliseconds>(ed - st).count();
    cout << "map find time: " << dur << " ms." << endl;

    st = chrono::steady_clock::now();
    for (int i = 0; i < insertn; i++)
        hashtable.find(i);
    ed = chrono::steady_clock::now();
    dur = chrono::duration_cast<chrono::milliseconds>(ed - st).count();
    cout << "hashtable find time: " << dur << " ms." << endl;

    return 0;
}