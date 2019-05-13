/*  backingStore.h */
#ifndef BACKINGSTORE_H
#define BACKINGSTORE_H

#include <iostream>
#include <fstream>
using namespace std;
class BackingStore
{
    public:
        BackingStore(); // open the backing store
         // upon receiving signal from page table, we retreive a value from backing store
        int read(int page_number, int offset);
        ~BackingStore(); // close the backing store
        ifstream media_;
};

#endif