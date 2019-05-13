/* MemoryManager.h */

#pragma once

struct FreeFrameList
{
    int ff_list;
};

class MemoryManager
{
    public:
        MemoryManager();
        int getFrameNumber();
        struct FreeFrameList freeFrames_;
};

