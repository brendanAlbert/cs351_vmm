#include "ram.h"

RAM::RAM()
{
    for(int i = 0; i < NUMBER_FRAMES; ++i)
    {
        Status s;
        status.at(i) = s;
    }
}