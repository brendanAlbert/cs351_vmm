#pragma once

#include "Word.h"
#include <exception>

using namespace std;

class PageFault : public exception
{
    public:
        PageFault();
        Word pageNumber_;
        virtual const char* what() const throw() { return "My exception happened."; }
};