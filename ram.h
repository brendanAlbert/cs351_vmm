
/*ram.h*/
#ifndef RAM_H
#define RAM_H

#include <array>
struct Status
{
    bool accessed;
    bool dirty;
};

const int NUMBER_FRAMES = 256;

struct Frame
{
    int physical_address;
    int frame_number;
    int data_value;
};


class RAM
{       
    public:
        RAM();
        // void read<T>();
        // An array of 256 Statuses
        std::array<Frame,NUMBER_FRAMES > memory;
        std::array<Status,NUMBER_FRAMES > status;
    private:
        
};


#endif