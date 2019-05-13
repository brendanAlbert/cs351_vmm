#include <iostream>
#include <bitset>
#include <fstream>
#include <string>

#include "tlb.cpp"

using namespace std;


#define BYTE_SIZE_256 256

class Frame
{
    public:
        Frame()
        {
            data[FRAME_SIZE] = {0};
        }
        char data[];
    private:
        const uint16_t FRAME_SIZE = 256;
};

class PageTable
{
    public:
        PageTable()
        {
            uint16_t table[PAGE_TABLE_SIZE_256];
        }
    private:
        const uint16_t PAGE_TABLE_SIZE_256 = 256;
        uint16_t table[];
};

public:
        MemoryManagementUnit(char * filename)
        {
            // array of 1000 logical addresses
            u_int16_t logicalAddresses[NUMBER_LOGICAL_ADDRESSES];
            // pass logicalAddresses array by reference to be filled with 'logical' addresses from addresses.txt file
            readLogicalAddresses(filename, logicalAddresses);
        }

        void getPageNumberAndOffset(u_int16_t address, u_int16_t & page_number, u_int16_t & offset)
        {
            // these two lines are just for visualization purposes; they can be commented out and the VMM is unaffected
            // string binary = bitset<16>(address).to_string();
            // cout << binary << "\n";

            // shifting 8 bits to the right gives the 8 leftmost bits, the PageNumber
            unsigned int left_most_8bits = address >> 8;
            // masking the 8 right bits gives the 8 rightmost bits, the Offset
            unsigned int right_most_8bits = address & 0xFF;

            cout << "left_most_8bits = page number: " << left_most_8bits << " <- index of page table\n";
            cout << "right_most_8bits = offset: " << right_most_8bits << "\n";

            // we passed page_number and offset unsigned ints by reference so we can gain access to them outside of this function
            page_number = left_most_8bits;
            offset = right_most_8bits;
        }

        
    private:
        void readLogicalAddresses(char * address_file, u_int16_t logicalAddressArray[])
        {
            ifstream ifs(address_file);
            int count = 0;
            if(ifs.is_open())
            {
                char c;
                string number;
                while(ifs.get(c))
                {
                    if(c == '\n')
                    {
                        logicalAddressArray[count] = atoi(number.c_str());
                        number = "";
                        ++count;
                    }
                    // cout << c;
                    number += c;

                    
                }
                ifs.close();
            }
            cout << "count : "  << count << "\n";
        }
        const u_int16_t NUMBER_LOGICAL_ADDRESSES = 1000;
        u_int16_t logicalAddresses[];






int main(int argc, char **argv)
{   
    // argv[1] == "addresses.txt"
    MemoryManagementUnit memory_management_unit(argv[1]);
    BackingStore backing_store;

    
    

    // these two u_int16_ts (unsigned ints) are to be passed by reference to the 'getPageNumberAndOffset' function
    u_int16_t page_number, offset;

    for (int i = 0; i < 10; ++i)
    {
        // when this function finishes, both parameters contain updated pg number and offset values from the current logical address
        memory_management_unit.getPageNumberAndOffset(logicalAddresses[i], page_number, offset);

        // the next step right here is to check the page_number against the TLB
        // cout << "checking TLB: for pg_number: " << page_number << "\n" 
        // << "entry " << (memory_management_unit.checkTLB(page_number) ? " found!\n" : "not found.\n");
        // if there is a TLB hit, we then use the frame number * byte_size + offset to access the value from physical memory

        // if there is a TLB miss, we then have to look up the frame_number from the page table


        // we use these values to determine the physical address (which we get from the backing_store) 
        // by this equation: physical address = (frame number * byte size) + offset
        // cout << i+1 << " value from backing_store_buffer: " << +static_cast<char>(backing_store_buffer[page_number * BYTE_SIZE_256 + offset]) << "\n\n";
    }

    
    
    return 0;
}


class BackingStore() {
    public:
            BackingStore()
            {
                
                is.open("BACKING_STORE.bin", ifstream::binary);
                if(is)
                {
                    // is.seekg(0, is.end);
                    // int length = is.tellg();

                    // we need to seek to the pageNumber * BYTE_SIZE_256 + offset
                    is.seekg(0, is.beg);

                    Frame physical_address_frame;
                    
                    is.read(physical_address_frame.data, BYTE_SIZE_256);

                }
                else
                {
                    cout << "Error opening BACKING_STORE.bin.  Exiting.\n";
                    exit(EXIT_FAILURE);
                }
            }
            ~BackingStore()
            {
                is.close();
            }
        private:
            ifstream is;

};