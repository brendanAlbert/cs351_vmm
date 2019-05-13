/*  backingStore.cpp */

#include "backingStore.h"

BackingStore::BackingStore()
{
    media_.open("BACKING_STORE.bin", std::ifstream::binary);

}

int BackingStore::read(int page_number, int offset)
{
    if(media_)
    {
        media_.seekg(page_number * 256 + offset);
        char frame[256];
        media_.read(frame, 256);
        std::cout<< +static_cast<char>(frame[0]) << endl;
        return +static_cast<char>(frame[0]);
    }
    return -1;
}

BackingStore::~BackingStore()
{
    media_.close();
}