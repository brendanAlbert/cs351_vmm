#include "MemoryManager.h"

MemoryManager::MemoryManager()
{
   this->freeFrames_.ff_list = 0;
}

int MemoryManager::getFrameNumber()
{
    return this->freeFrames_.ff_list++;   
}