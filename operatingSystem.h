class OperatingSystem
{
    // PageReplacementAlgorithm
        // FIFO
        // LRU
    // PageTableEntry
    // MemoryManager
    // ProcessControlBlock
};

class PageReplacementAlgorithm
{
    public:
        ~PageReplacementAlgorithm();
        Word findVictim();
        PageReplacementAlgorithm& getPRA();
        void updateUsage();
    protected:
        PageReplacementAlgorithm();
    private:

};

class MemoryManager
{
    public:
        MemoryManager& instance();
        MemoryManager();
        // I need to look up again how to overload an operator
        // looks like this needs the = operator overloaded?
        //MemoryManager& operator=
        void pageIn();
    private:
        FreeFrameList freeFrames_;
        MemoryManager();
};

class PageTableEntry
{
    public:
        unsigned int frameNumber;
        bool valid;
};

class ProcessControlBlock
{
    public:
        PageTable myPageTable;
};

class LeastRecentlyUsedAlgorithm
{
    public:
        Word findVictim();
        LeastRecentlyUsedAlgorithm();
        void updateUsage();
    private:
        UsedList lruList;
};

class FirstInFirstOutAlgorithm
{
    public:
        Word findVictim();
        FirstInFirstOutAlgorithm();
    private:
        Word front;
};